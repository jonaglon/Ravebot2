
///////////////// Circles in time //////////////////////////////
void bodyCirclesInTime() {
  if (thisBeat32 > 7)
    return;  

  uint32_t percentThroughPattern = (timeyInTime % 32768)/364;     // 0-90 over 2 bars

  uint16_t beat4 = sixteenBeats % 4;  
  if (beat4 == 0) {
    setSectionLed(13, (percentThroughPattern + 32) % 90, 0, 0, 0, 255);
    setSectionLed(13, (percentThroughPattern + 33) % 90, 0, 0, 0, 255);
    setSectionLed(13, (percentThroughPattern + 34) % 90, 0, 0, 0, 255);
    setSectionLed(14, (percentThroughPattern + 54) % 90, 100, 50, 90, 0);
    setSectionLed(14, (percentThroughPattern + 55) % 90, 100, 50, 90, 0);
    setSectionLed(14, (percentThroughPattern + 56) % 90, 100, 50, 90, 0);
    setSectionLed(15, (percentThroughPattern + 76) % 90, 0, 130, 130, 0);
    setSectionLed(15, (percentThroughPattern + 77) % 90, 0, 130, 130, 0);
    setSectionLed(15, (percentThroughPattern + 78) % 90, 0, 130, 130, 0);
    setSectionLed(16, (percentThroughPattern + 9) % 90, 130, 0, 130, 0);
    setSectionLed(16, (percentThroughPattern + 10) % 90, 130, 0, 130, 0);
    setSectionLed(16, (percentThroughPattern + 11) % 90, 130, 0, 130, 0);
  } else if (beat4 == 1) {
    setSectionLed(13, (percentThroughPattern + 32) % 90, 130, 0, 130, 0);
    setSectionLed(13, (percentThroughPattern + 33) % 90, 130, 0, 130, 0);
    setSectionLed(13, (percentThroughPattern + 34) % 90, 130, 0, 130, 0);
    setSectionLed(14, (percentThroughPattern + 54) % 90, 0, 0, 0, 255);
    setSectionLed(14, (percentThroughPattern + 55) % 90, 0, 0, 0, 255);
    setSectionLed(14, (percentThroughPattern + 56) % 90, 0, 0, 0, 255);
    setSectionLed(15, (percentThroughPattern + 76) % 90, 100, 50, 90, 0);
    setSectionLed(15, (percentThroughPattern + 77) % 90, 100, 50, 90, 0);
    setSectionLed(15, (percentThroughPattern + 78) % 90, 100, 50, 90, 0);
    setSectionLed(16, (percentThroughPattern + 9) % 90, 0, 130, 130, 0);
    setSectionLed(16, (percentThroughPattern + 10) % 90, 0, 130, 130, 0);
    setSectionLed(16, (percentThroughPattern + 11) % 90, 0, 130, 130, 0);
  } else if (beat4 == 2) {
    setSectionLed(13, (percentThroughPattern + 32) % 90, 0, 130, 130, 0);
    setSectionLed(13, (percentThroughPattern + 33) % 90, 0, 130, 130, 0);
    setSectionLed(13, (percentThroughPattern + 34) % 90, 0, 130, 130, 0);
    setSectionLed(14, (percentThroughPattern + 54) % 90, 130, 0, 130, 0);
    setSectionLed(14, (percentThroughPattern + 55) % 90, 130, 0, 130, 0);
    setSectionLed(14, (percentThroughPattern + 56) % 90, 130, 0, 130, 0);
    setSectionLed(15, (percentThroughPattern + 76) % 90, 0, 0, 0, 255);
    setSectionLed(15, (percentThroughPattern + 77) % 90, 0, 0, 0, 255);
    setSectionLed(15, (percentThroughPattern + 78) % 90, 0, 0, 0, 255);
    setSectionLed(16, (percentThroughPattern + 9) % 90, 100, 50, 90, 0);
    setSectionLed(16, (percentThroughPattern + 10) % 90, 100, 50, 90, 0);
    setSectionLed(16, (percentThroughPattern + 11) % 90, 100, 50, 90, 0);
  } else if (beat4 == 3) {
    setSectionLed(13, (percentThroughPattern + 32) % 90, 100, 50, 90, 0);
    setSectionLed(13, (percentThroughPattern + 33) % 90, 100, 50, 90, 0);
    setSectionLed(13, (percentThroughPattern + 34) % 90, 100, 50, 90, 0);
    setSectionLed(14, (percentThroughPattern + 54) % 90, 0, 130, 130, 0);
    setSectionLed(14, (percentThroughPattern + 55) % 90, 0, 130, 130, 0);
    setSectionLed(14, (percentThroughPattern + 56) % 90, 0, 130, 130, 0);
    setSectionLed(15, (percentThroughPattern + 76) % 90, 130, 0, 130, 0);
    setSectionLed(15, (percentThroughPattern + 77) % 90, 130, 0, 130, 0);
    setSectionLed(15, (percentThroughPattern + 78) % 90, 130, 0, 130, 0);
    setSectionLed(16, (percentThroughPattern + 9) % 90, 0, 0, 0, 255);
    setSectionLed(16, (percentThroughPattern + 10) % 90, 0, 0, 0, 255);
    setSectionLed(16, (percentThroughPattern + 11) % 90, 0, 0, 0, 255);
  }
}

////////////////////////// Circle Squiggles //////////////////////////
uint8_t squigglePattern[10][17][2] {
    //   0         1         2         3        4        5          6         7         8         9        10       11        12        13        14       15     
    {{15, 22}, {15, 44}, {15, 66}, {15,  0}, {15, 22}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {16, 44}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {15, 44}, {15, 66}, {15,  0}, {15, 22}, {15, 44}, {15, 66}, {15,  0}, {15, 22}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {15, 44}, {15, 66}, {15,  0}, {15, 22}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {13,  0}, {13, 22}, {13, 44}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {13,  0}, {13, 22}, {13, 44}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {16, 44}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {13,  0}, {13, 22}, {13, 44}, {13, 67}, {13,  0}, {13, 22}, {13, 44}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {14, 67}, {14, 44}, {14, 22}, {14,  0}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {16, 44}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {14, 67}, {14, 44}, {14, 22}, {14,  0}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {13,  0}, {13, 22}, {13, 44}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {16, 44}, {16, 22}, {16,  0}, {16, 66}, {16, 44}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {14, 67}, {14, 44}, {14, 22}, {14,  0}, {14, 67}, {14, 44}, {14, 22}, {14,  0}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {15, 22}},
    {{15, 22}, {14, 67}, {14, 44}, {14, 22}, {14,  0}, {14, 67}, {14, 44}, {14, 22}, {13, 67}, {13,  0}, {13, 22}, {13, 44}, {13, 67}, {16, 22}, {16,  0}, {16, 66}, {15, 22}}
};

uint16_t squiggleLedDistance[17] {0, 728, 1456, 2185, 2913, 3641, 4369, 5097, 5825, 6554, 7282, 8010, 8738, 9466, 10194, 10923, 11651};

void circleSquiggleRainbow1() {
  for (int16_t arrayNum=0; arrayNum < 11; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+98304, 80, 0, 200, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 11; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+81920, 35, 0, 65, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 11; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+65536, 0, 0, 255, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 9; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+49152, 0, 255, 0, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 9; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+32768, 255, 255, 0, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 9; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+16384, 255, 65, 0, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 9; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum], 255, 0, 0, 0);
  }
}

void circleSquiggleWhiteEight() {
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+114688, 0, 0, 0, 255);
  }
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+98304, 0, 0, 0, 255);
  }
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+81920, 0, 0, 0, 255);
  }
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+65536, 0, 0, 0, 255);
  }
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+49152, 0, 0, 0, 255);
  }
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+32768, 0, 0, 0, 255);
  }
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+16384, 0, 0, 0, 255);
  }
  for (int16_t arrayNum=0; arrayNum < 10; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum], 0, 0, 0, 255);
  }
}

void circleSquiggleGood() {
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+180224, 50, 0, 240, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+163840, 0, 100, 150, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+147456, 150, 0, 100, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+131072, 80, 40, 110, 0);
  }
  
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+114688, 50, 0, 240, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+98304, 0, 100, 150, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+81920, 150, 0, 100, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+65536, 80, 40, 110, 0);
  }

  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+49152, 50, 0, 240, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+32768, 0, 100, 150, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum]+16384, 150, 0, 100, 0);
  }
  for (int16_t arrayNum=0; arrayNum < 12; arrayNum++) {
    circleSquiggle(squiggleLedDistance[arrayNum], 80, 40, 110, 0);
  }
}

void circleSquiggle(int32_t offset, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  int32_t placeInQueue = ((timeyInTime+offset) % 262144) / 16384;
  int32_t thisPattern = ((timeyInTime+offset) % 2621440) / 262144;

  uint8_t tube = squigglePattern[thisPattern][placeInQueue][0];
  uint8_t startLed = squigglePattern[thisPattern][placeInQueue][1];
  int32_t percentThroughPattern = ((percentThroughBeat+offset)%16384)/712;

  // if (((tube == 0 || tube == 3) && moveForwards) || ((tube == 1 || tube == 2) && !moveForwards)) {

  if (tube == 13 || tube == 15) {
    setSectionLed(tube, startLed + percentThroughPattern, r, g, b, w);
  } else {
    setSectionLed(tube, startLed + (23 - percentThroughPattern), r, g, b, w);
  }
}



//////////////////////////// Me Hearties /////////////////

void heartInTime() {
  if (thisBeat8 == 0) {
    setSection(2, 128, 0, 0, 0);
  } else if (thisBeat8 == 1) {
    setSection(1, 128, 0, 0, 0);
  } else if (thisBeat8 == 2) {
    setSection(2, 255, 0, 0, 0);
  } else if (thisBeat8 == 3) {
    setSection(1, 255, 0, 0, 0);
  }
}


//////////////// Sections in time, BORING //////////////////
void sectionsInTime() {
  if (thisBeat32 > 3)
    return;
  
  if (thisBeat32 == 0) {
    setSection(15, 255, 0, 0, 0);
  } else if (thisBeat32 == 1) {
    setSection(16, 0, 255, 0, 0);
  } else if (thisBeat32 == 2) {
    setSection(13, 0, 0, 255, 0);
  } else if (thisBeat32 == 3) {
    setSection(14, 0, 0, 0, 255);
  };
}

int16_t numLedsTube = 88;
int16_t numLedsPerBeat=22;
int16_t beatCompNum = 16384/numLedsPerBeat; // this is the 16384 beat% / those 30 leds. (182/546 - for 30/90)
uint8_t tuber1, tubeg1, tubeb1, tubew1, tuber2, tubeg2, tubeb2, tubew2, tuber3, tubeg3, tubeb3, tubew3, tuber4, tubeg4, tubeb4, tubew4; 
void tubesInTime() {  
  for(int16_t j = 0; j < numLedsTube; j++) {
    int32_t distanceFromBeat = quickAbsolute(((j%numLedsPerBeat)*beatCompNum)-percentThroughBeat);

    int16_t ledColour = 255 - (distanceFromBeat/10);
    if (ledColour <= 0)
      continue;
      
    if (beatCycle && thisBeat4 == 0) {
      setGoodRandomColorVars();
      tuber1 = goodColR;
      tubeg1 = goodColG;
      tubeb1 = goodColB;
      tubew1 = goodColW;
    } else if (beatCycle && thisBeat4 == 1) {
      setGoodRandomColorVars();
      tuber2 = goodColR;
      tubeg2 = goodColG;
      tubeb2 = goodColB;
      tubew2 = goodColW;
    } else if (beatCycle && thisBeat4 == 2) {
      setGoodRandomColorVars();
      tuber3 = goodColR;
      tubeg3 = goodColG;
      tubeb3 = goodColB;
      tubew3 = goodColW;
    } else if (beatCycle) {
      setGoodRandomColorVars();
      tuber4 = goodColR;
      tubeg4 = goodColG;
      tubeb4 = goodColB;
      tubew4 = goodColW;
    }

    setSectionLed(13, j, tuber1, tubeg1, tubeb1, tubew1);
    setSectionLed(14, j, tuber2, tubeg2, tubeb2, tubew2);
    setSectionLed(15, j, tuber3, tubeg3, tubeb3, tubew3);
    setSectionLed(16, j, tuber4, tubeg4, tubeb4, tubew4);
  }
}

void bigSpeakerThreeRevolvers() {
  int16_t thisLed1 = ((timeyInTime/512)-12)%203;
  int16_t thisLed2 = ((timeyInTime/512)+56)%203;
  int16_t thisLed3 = ((timeyInTime/512)+113)%203;

  setSectionLed(0, thisLed1, 0, 0, 0, 20);
  setSectionLed(0, thisLed1+1, 0, 0, 0, 40);
  setSectionLed(0, thisLed1+2, 0, 0, 0, 80);
  for(int8_t j = 3; j < 11; j++)
    setSectionLed(0, thisLed1+j, 0, 0, 0, 255);
  setSectionLed(0, thisLed1+11, 0, 0, 0, 80);
  setSectionLed(0, thisLed1+12, 0, 0, 0, 40);
  setSectionLed(0, thisLed1+13, 0, 0, 0, 20);
  
  setSectionLed(0, thisLed2, 0, 0, 0, 20);
  setSectionLed(0, thisLed2+1, 0, 0, 0, 40);
  setSectionLed(0, thisLed2+2, 0, 0, 0, 80);
  for(int8_t j = 3; j < 11; j++)
    setSectionLed(0, thisLed2+j, 0, 0, 0, 255);
  setSectionLed(0, thisLed2+11, 0, 0, 0, 80);
  setSectionLed(0, thisLed2+12, 0, 0, 0, 40);
  setSectionLed(0, thisLed2+13, 0, 0, 0, 20);
  
  setSectionLed(0, thisLed3, 0, 0, 0, 20);
  setSectionLed(0, thisLed3+1, 0, 0, 0, 40);
  setSectionLed(0, thisLed3+2, 0, 0, 0, 80);
  for(int8_t j = 3; j < 11; j++)
    setSectionLed(0, thisLed3+j, 0, 0, 0, 255);
  setSectionLed(0, thisLed3+11, 0, 0, 0, 80);
  setSectionLed(0, thisLed3+12, 0, 0, 0, 40);
  setSectionLed(0, thisLed3+13, 0, 0, 0, 20);
  
}

uint8_t r1 = 0;
uint8_t g1 = 0;
uint8_t b1 = 0;
uint8_t w1 = 0;
uint8_t r2 = 0;
uint8_t g2 = 0;
uint8_t b2 = 0;
uint8_t w2 = 0;
uint8_t r3 = 0;
uint8_t g3 = 0;
uint8_t b3 = 0;
uint8_t w3 = 0;
uint8_t r4 = 0;
uint8_t g4 = 0;
uint8_t b4 = 0;
uint8_t w4 = 0;
void bigSpeakerInTimeFourTings() {
  int16_t thisLed1 = ((timeyInTime/512)-12)%203;
  int16_t thisLed2 = ((timeyInTime/512)+39)%203;
  int16_t thisLed3 = ((timeyInTime/512)+89)%203;
  int16_t thisLed4 = ((timeyInTime/512)+139)%203;

  if (beatCycle) {
    setGoodRandomColorVars();
    r1 = goodColR; g1 = goodColG; b1 = goodColB; w1 = goodColW;
    setGoodRandomColorVars();
    r2 = goodColR; g2 = goodColG; b2 = goodColB; w2 = goodColW;
    setGoodRandomColorVars();
    r3 = goodColR; g3 = goodColG; b3 = goodColB; w3 = goodColW;
    setGoodRandomColorVars();
    r4 = goodColR; g4 = goodColG; b4 = goodColB; w4 = goodColW;
  }

  for(int8_t j = 0; j < 9; j++)
    setSectionLed(0, thisLed1+j, r1, g1, b1, w1);
  
  for(int8_t j = 0; j < 9; j++)
    setSectionLed(0, thisLed2+j, r2, g2, b2, w2);
  
  for(int8_t j = 0; j < 9; j++)
    setSectionLed(0, thisLed3+j, r3, g3, b3, w3);
  
  for(int8_t j = 0; j < 9; j++)
    setSectionLed(0, thisLed4+j, r4, g4, b4, w4);

}


