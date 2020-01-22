/* ************************
       RECEIVE FROM MEGA
************************* */

void receiveFromMega() {
  while (Serial1.available()) {
    char strIn[4];
    int16_t i=0;
    delay(2); //allows all serial sent to be received together
    while(Serial1.available() && i<4) {
      strIn[i++] = Serial1.read();
    }
    strIn[i++]='\0';
    doSomethingWithPackageFromMega(atoi(strIn));
  }
}

void doSomethingWithPackageFromMega(int16_t package) {  
  int16_t function = package / 1000;
  int16_t message = package % 1000;

  if (testMode) {
    Serial.print("Message Received fn:");
    Serial.print(function);
    Serial.print("  msg:");
    Serial.println(message);
  }    

  if (function == 1) {
    if (message < 2) {
      doRobotTalkingLights(message);
    } else if (message < 4) {
      winkLeftMessage(message % 2);
    } else if (message < 6) {
      winkRightMessage(message % 2);
    } else if (message < 7) {
      lastEyeMoveTime = timey;
      changeEyeType();
    } else if (message < 8) {
      changeLightPattern();
    } else if (message < 9) {
      playRandomTune();
    } else if (message < 11) {
      changeOnOff(message % 2);
    } else if (message < 13) {
      changeManualAutomatic(message % 2);
    } else if (message < 40) {
      setDanceNumber(message % 20);
    }
  } else if (function == 2) {
    arcadeButtonPressed(message);
  } else if (function == 3) {
    ledIntensity=message;
    lastSentLedIntensity=message;
  } else if (function == 4) {
    // specific track was chosen on the keypad, play the track
    stayWithinGenre = false;
    playTune((message / 100), (message % 100), true);
  } else if (function == 5 || function == 6 || function == 7 || function == 8) {
    lastEyeMoveTime = timey;
    setEyeCoords(function, message);
  }
}

void setDanceNumber(int16_t message) {
  currentDance = message; 
}

void changeOnOff(int16_t message) {
  allOffBySection();
  if (message == 0) {
    robotSwitchedOn = false;
    tempMainVolume = mainVolume;
    setMainVolume(0);

    setSectionLed(5, 24, 50, 50, 50, 0);
    setSectionLed(5, 50, 50, 50, 50, 0);
    setSectionLed(5, 68, 50, 50, 50, 0);
    setSectionLed(5, 81, 50, 50, 50, 0);
    setSectionLed(5, 90, 50, 50, 50, 0);
    setSectionLed(5, 92, 50, 50, 50, 0);
    setSectionLed(5, 86, 50, 50, 50, 0);
    setSectionLed(5, 75, 50, 50, 50, 0);
    setSectionLed(5, 60, 50, 50, 50, 0);
    setSectionLed(5, 38, 50, 50, 50, 0);
    setSectionLed(5, 8, 50, 50, 50, 0);

    setSectionLed(6, 24, 50, 50, 50, 0);
    setSectionLed(6, 50, 50, 50, 50, 0);
    setSectionLed(6, 68, 50, 50, 50, 0);
    setSectionLed(6, 81, 50, 50, 50, 0);
    setSectionLed(6, 90, 50, 50, 50, 0);
    setSectionLed(6, 92, 50, 50, 50, 0);
    setSectionLed(6, 86, 50, 50, 50, 0);
    setSectionLed(6, 75, 50, 50, 50, 0);
    setSectionLed(6, 60, 50, 50, 50, 0);
    setSectionLed(6, 38, 50, 50, 50, 0);
    setSectionLed(6, 8, 50, 50, 50, 0);


    
    sendSerialToMega(2,0); // stops robot dancing and shows 0 on display
  } else {
    robotSwitchedOn = true;
    setMainVolume(tempMainVolume);
    setSectionLed(10, 0, 0, 255, 0, 0);
    setSectionLed(10, 1, 0, 255, 0, 0);
    setSectionLed(10, 2, 0, 255, 0, 0);
    setSectionLed(10, 3, 0, 255, 0, 0);
  }
  LEDS.show();
  delay(200);
}

void changeManualAutomatic(int16_t message) {
  allOffBySection();
  if (message == 0) {
    robotManualMode = false;
    setSectionLed(10, 0, 0, 0, 255, 0);
    setSectionLed(10, 1, 0, 0, 255, 0);
    setSectionLed(10, 2, 0, 0, 255, 0);
    setSectionLed(10, 3, 0, 0, 255, 0);
  } else {
    robotManualMode = true;
    setSectionLed(10, 0, 0, 0, 0, 255);
    setSectionLed(10, 1, 0, 0, 0, 255);
    setSectionLed(10, 2, 0, 0, 0, 255);
    setSectionLed(10, 3, 0, 0, 0, 255);
  }
  LEDS.show();
  delay(200);
}

int leftEyeXIn = 0;
int leftEyeYIn = 0;
void setEyeCoords(int16_t function, int16_t message) {
  if (function == 5) {
    leftEyeX = message-43;
    leftEyeXIn = message-43;
  } else if (function == 6) {
    leftEyeY = message-43;
    leftEyeYIn = message-43;    
  } else if (function == 7) {
    rightEyeX = message-43;
    if (leftEyeXIn > -2 && leftEyeXIn < 2)
      leftEyeX = rightEyeX;
  } else if (function == 8) {
    rightEyeY = message-43;
    if (leftEyeYIn > -2 && leftEyeYIn < 2)
      leftEyeY = rightEyeY;
  }
}

void arcadeButtonPressed(int16_t buttonNumber) {

  // Genre arcade button pressed
  if (buttonNumber < 8) {
    stayWithinGenre = true;
    playRandomTune(buttonNumber);
  }

  // Stop button
  if (buttonNumber == 8) {
    sendFullStop();
    stopAllAbletonClips();
    delay(20);
    startRobotVoiceTrack();
  }

  // Next button
  if (buttonNumber == 9) {
    playNextTrack();
  }

  // Vol down button
  if (buttonNumber == 10) {
    mainVolume = mainVolume - 8;
    setMainVolume(mainVolume);
  }

  // Vol up button
  if (buttonNumber == 11) {
    mainVolume = mainVolume + 8;
    setMainVolume(mainVolume);
  }

  // Previous tune
  if (buttonNumber == 12) {    
    playPreviousTrack();
  }

  // Play button
  if (buttonNumber == 13) {
    stayWithinGenre = false;
    playRandomTune();
  }

}

bool mutedVoice = false;
void doRobotTalkingLights(int16_t btnOnOffMessage) {
    if (btnOnOffMessage == 0)
    {
      robotTalking = true;
      robotTalkingOnTime = timey;
      setRobotVoiceVolume(120);
      if (!mutedVoice) {
        mainVolume = mainVolume - 15;
        setMainVolume(mainVolume);     
        mutedVoice=true; 
      }
    } else if (btnOnOffMessage == 1) {
      robotTalking = false;
      robotTalkingOffTime = timey;
    }
}

void checkForTurnRobotVoiceDown() {

  if (robotTalkingOffTime == 0)
    return;

  if (timey > (robotTalkingOffTime + 1600)) {
    setRobotVoiceVolume(0);
    robotTalkingOffTime=0;
    mainVolume = mainVolume + 15;
    setMainVolume(mainVolume);      
    mutedVoice = false;
  }
}


/* ************************
       SEND TO MEGA
************************* */
void sendBeatToMega() {
  sendSerialToMega(1, sixteenBeats);
}

void sendSerialToMega(int16_t function, int16_t message) {
  if (testMode) {
    Serial.print("* * SENDING TO MEGA FN:");
    Serial.print(function);
    Serial.print("   MSG:");
    Serial.println(message);
  }

  if (megaAttached) {
    char strOut[4]; // the message from the mega
    itoa((function * 1000) + message, strOut, 10); //Turn value into a character array
    Serial1.write(strOut, 4);
  }
}

