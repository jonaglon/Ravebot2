/* ******************************* EYES & MOUTH ********************************** */
bool eyesAutomatic = false;
bool whiteEyeBackground = false;

void doFace() {
  eyeController();
  doDialRainbow();
  doTalkingLights();
}

void doDialRainbow() {
  uint32_t percentThroughPattern = timeyInTime/1024;     // 0-255 over 2 bars
  
  // 26 ligths in the dial
  for(uint8_t j = 0; j < 26; j++) {
    SetRgbwWheelVars((percentThroughPattern+(j*6))%256);
    setSectionLed(9, 26-j, wheelR, wheelG, wheelB, 0);   
  }
}

void eyeController() {
  if (lastEyeMoveTime+1000 > timey) {   // TODO - should be 20000
    if (eyesAutomatic) {
      resetEyes();
      eyesAutomatic = false;
    }
    doNormalEyes();
  } else {
    if (!eyesAutomatic) {
      resetEyes();
      eyesAutomatic = true;
    }
    doAutomaticEyes();
  }
}

void resetEyes() {
  eyePrimaryR = 110;
  eyePrimaryG = 150;
  eyePrimaryB = 150;
  leftEyeX = 0;
  leftEyeY = 0;
  rightEyeX = 0;
  rightEyeY = 0;
}


void doAutomaticEyes() {
  //  if (beatCycle && ((sixteenBeats%8) == 4)) {
  
  if (whiteEyeBackground) {
    for(uint8_t j = 0; j < 93; j++) {
      setSectionLed(5, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
      setSectionLed(6, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    }
  }
  drawEyeIrisNoPupil(ledSections[5], 55+leftEyeX, 55-leftEyeY, 0, 0, 0, 0);
  drawEyeIrisNoPupil(ledSections[6], 55+rightEyeX, 55-rightEyeY, 0, 0, 0, 0);
  doBlinking();
  doLeftWink();
  doRightWink();
}

void doNormalEyes() {
  if (whiteEyeBackground) {
    for(uint8_t j = 0; j < 93; j++) {
      setSectionLed(5, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
      setSectionLed(6, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    }
  }
  drawIrisAndPupil();
  doBlinking();
  doLeftWink();
  doRightWink();
}

void drawIrisAndPupil() {
  // iris
  drawEyeHexagon(ledSections[5], 55+leftEyeX, 55-leftEyeY, 26, 42, 0, 0, 0, 0);
  drawEyeHexagon(ledSections[6], 55+rightEyeX, 55-rightEyeY, 26, 42, 0, 0, 0, 0);

  // pupil
  drawEyeSquare(ledSections[5], 55+leftEyeX, 55-leftEyeY, 7, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
  drawEyeSquare(ledSections[6], 55+rightEyeX, 55-rightEyeY, 7, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
}

void changeEyeType() {
  whiteEyeBackground = !whiteEyeBackground;
}


// Eye patterns
void doStonerEyes() {

  for(uint8_t j = 0; j < 93; j++) {
    if (eyeCoords[j][1] < 56) {
      setSectionLed(5, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
      setSectionLed(6, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    } else {
      setSectionLed(5, j, 0, 0, 0, 0);
      setSectionLed(6, j, 0, 0, 0, 0);
    }
  }

  // dark eye squares
  drawEyeHexagon(ledSections[5], 55+leftEyeX, 29-leftEyeY, 20, 35, 0, 0, 0, 0);
  drawEyeHexagon(ledSections[6], 55+rightEyeX, 29-rightEyeY, 20, 35, 0, 0, 0, 0);

  // pupil
  drawEyeSquare(ledSections[5], 55+leftEyeX, 29-leftEyeY, 8, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
  drawEyeSquare(ledSections[6], 55+rightEyeX, 29-rightEyeY, 8, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);

  doLeftWink();
  doRightWink();
}

void heartEyes() {

  for(uint8_t j = 0; j < 93; j++) {
    setSectionLed(5, j, 0, 0, 0, 0);
    setSectionLed(6, j, 0, 0, 0, 0);
  }

  for(uint8_t j = 0; j < 56; j++) {
    setSectionLed(5, eyeHeartLeds[j], eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, eyeHeartLeds[j], eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
  }
}

void pacManEyes() {
  // 16384 is a beat length  1365 is an 12th-ish
  //int animationStep = percentThroughBeat / 1365;
  
  uint32_t animationStep1 = (timeyInTime / 2048)%8;
  uint32_t animationStep2 = (timeyInTime / 1024)%16;
  
  for(uint8_t j = 0; j < 93; j++) {
    if (pacManAnimationMask[(animationStep2)%16][j]) {
      setSectionLed(6, j, 120, 120, 0, 0);
    } else if (pacManAnimationMask2[(animationStep1+4)%8][j]) {
      setSectionLed(6, j, 0, 0, 0, 0);
    } else {
      setSectionLed(6, j, 255, 255, 255, 0);
    }
  }
  for(uint8_t j = 0; j < 93; j++) {
    if (pacManAnimationMask2[animationStep1][j]) {
      setSectionLed(5, j, 0, 0, 0, 0);
    } else {
      setSectionLed(5, j, 255, 255, 255, 0);
    }
  }
}

void smileyEyes() {
  for(uint8_t j = 0; j < 93; j++) {
    setSectionLed(5, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, j, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
  }
  for(uint8_t j = 0; j < 24; j++) {
    setSectionLed(5, eyeSmileyLeds[j], 0, 0, 0, 0);
    setSectionLed(6, eyeSmileyLeds[j], 0, 0, 0, 0);
  }
}

unsigned long blinkStart=4000;
const uint32_t blinkLength=240;
void doBlinking() {
  uint32_t drawTo = 0;
  //uint32_t drawTo2 = 0;
  uint32_t blinkHeight = 60;
  
  if (timey > (blinkStart + blinkLength)) {
    // blink over, reset
    if (random(9) == 0) {
      blinkStart = timey + random(400);
    } else {
      blinkStart = timey + random(4000,9000);
    }
  } else if (timey > blinkStart) {
    uint32_t percIntoBlink = ((timey - blinkStart)*100)/(blinkLength/2);
    if (timey > (blinkStart + (blinkLength/2))) {
      // on way up
      drawTo = ((blinkHeight * percIntoBlink)/100)-blinkHeight+50;
    } else {
      // on way down
      drawTo = blinkHeight+50-((blinkHeight * percIntoBlink)/100);
    }
    for(uint8_t j = 0; j < 93; j++) {
      if (eyeCoords[j][1] < 110 - drawTo) {
          setSectionLed(5, j, 0, 0, 0, 0);
      }
      if (eyeCoords[j][1] > drawTo) {
          setSectionLed(5, j, 0, 0, 0, 0);
      }
      if (eyeCoords[j][1] < 110 - drawTo) {
          setSectionLed(6, j, 0, 0, 0, 0);
      }
      if (eyeCoords[j][1] > drawTo) {
          setSectionLed(6, j, 0, 0, 0, 0);
      }
    }
  }
}

uint32_t lWinkStart=0;
uint32_t rWinkStart=0;
uint32_t lWinkEnd=0;
uint32_t rWinkEnd=0;
bool lWinking = false;
bool rWinking = false;
const uint16_t winkLength=350;

// Note, left and right winks are copied and pasted, change both the same.
void doLeftWink() {
  if (!lWinking)
    return;

  uint16_t drawTo = 0;  
  if (lWinkEnd!=0 && (timey > (lWinkEnd + (winkLength/2)))) {
    // blink over, reset
    lWinking = false;
    lWinkEnd=0;
    drawTo = 110;
  } else if (lWinkEnd==0 && timey < (lWinkStart + (winkLength/2))) {
    // on way down
    uint32_t percIntoBlink = ((timey - lWinkStart)*100)/(winkLength/2);
    drawTo = 110-((60 * percIntoBlink)/100);
  } else if (lWinkEnd!=0) {
    // on way up
    uint32_t percIntoBlink = ((timey - lWinkEnd)*100)/(winkLength/2);
    drawTo = 50+((60 * percIntoBlink)/100);
  } else {
    // in the middle
    for(uint16_t j = 0; j < 93; j++) {
      setSectionLed(6, j, 0, 0, 0, 0);
    }
    setSectionLed(6, 24, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 50, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 68, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 81, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 90, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 92, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 86, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 75, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 60, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6, 38, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(6,  8, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    return;
  }
  for(uint16_t j = 0; j < 93; j++) {
    if (eyeCoords[j][1] < 110 - drawTo) {
        setSectionLed(6, j, 0, 0, 0, 0);
    }
    if (eyeCoords[j][1] > drawTo) {
        setSectionLed(6, j, 0, 0, 0, 0);
    }
  }
}

void doRightWink() {
  if (!rWinking)
    return;

  uint16_t drawTo = 0;  
  if (rWinkEnd!=0 && (timey > (rWinkEnd + (winkLength/2)))) {
    // blink over, reset
    rWinking = false;
    rWinkEnd=0;
    drawTo = 110;
  } else if (rWinkEnd==0 && timey < (rWinkStart + (winkLength/2))) {
    // on way down
    uint32_t percIntoBlink = ((timey - rWinkStart)*100)/(winkLength/2);
    drawTo = 110-((60 * percIntoBlink)/100);
  } else if (rWinkEnd!=0) {
    // on way up
    uint32_t percIntoBlink = ((timey - rWinkEnd)*100)/(winkLength/2);
    drawTo = 50+((60 * percIntoBlink)/100);
  } else {
    // in the middle
    for(uint16_t j = 0; j < 93; j++) {
      setSectionLed(5, j, 0, 0, 0, 0);
    }
    setSectionLed(5, 24, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 50, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 68, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 81, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 90, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 92, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 86, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 75, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 60, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5, 38, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    setSectionLed(5,  8, eyePrimaryR, eyePrimaryG, eyePrimaryB, 0);
    return;
  }
  for(uint16_t j = 0; j < 93; j++) {
    if (eyeCoords[j][1] < 110 - drawTo) {
        setSectionLed(5, j, 0, 0, 0, 0);
    }
    if (eyeCoords[j][1] > drawTo) {
        setSectionLed(5, j, 0, 0, 0, 0);
    }
  }
}

void winkLeftMessage(uint16_t blinkOnOffMessage) {
  if (blinkOnOffMessage == 0) {
    // start new wink
    lWinkStart=timey;
    lWinking = true;
    lWinkEnd=0;
    // push forward the next blink
    blinkStart = timey + random(3000,8000);
  } else if (blinkOnOffMessage == 1) {
    // end wink
    lWinkEnd=timey;
  }
}

void winkRightMessage(uint16_t blinkOnOffMessage) {
  if (blinkOnOffMessage == 0) {
    // start new wink
    rWinkStart=timey;
    rWinking = true;
    rWinkEnd=0;
    // push forward the next blink
    blinkStart = timey + random(3000,8000);
  } else if (blinkOnOffMessage == 1) {
    // end wink
    rWinkEnd=timey;
  }
}


void doTalkingLights() {

  for(uint16_t j = 0; j < numLedsInSection(7); j++) {
    setSectionLed(7, j, 0, 0, 0, 0);
  }
  
  if (robotTalking) {
    setLedDirect(ledSections[7]+8, 255, 60, 60, 100, true);
    setLedDirect(ledSections[7]+9, 255, 60, 60, 100, true);
    
    if (timey > (robotTalkingOnTime + 40)) {
      setLedDirect(ledSections[7]+7, 255, 60, 60, 100, true);
      setLedDirect(ledSections[7]+10, 255, 60, 60, 100, true);
    }
    
    if (timey > (robotTalkingOnTime + 80)) {
      setLedDirect(ledSections[7]+6, 255, 60, 60, 100, true);
      setLedDirect(ledSections[7]+11, 255, 60, 60, 100, true);
    }
    
    if (timey > (robotTalkingOnTime + 110)) {
      setLedDirect(ledSections[7]+5, 255, 60, 60, 100, true);
      setLedDirect(ledSections[7]+12, 255, 60, 60, 100, true);
    }
    
    if (timey > (robotTalkingOnTime + 135)) {
      setLedDirect(ledSections[7]+4, 255, 60, 60, 100, true);
      setLedDirect(ledSections[7]+13, 255, 60, 60, 100, true);
    }
    
    if (timey > (robotTalkingOnTime + 150)) {
      setLedDirect(ledSections[7]+3, 255, 60, 60, 100, true);
      setLedDirect(ledSections[7]+14, 255, 60, 60, 100, true);
    }
  }  
}
