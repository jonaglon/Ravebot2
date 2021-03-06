const short speedDivisor = 1024;  /* small numbers equals faster strips! */

int16_t ledToLight;

void doTwinkles() {

  for (int16_t twinky = 0; twinky < usedTwinkleCount[currentLightPattern]; twinky++) {

    int16_t newLedNum = myTwinkles[twinky].ledNum;
    if (myTwinkles[twinky].speedy != 0)
    {
        uint32_t ticky = (twinkleTime / speedDivisor)/quickAbsolute(myTwinkles[twinky].speedy);
        if (myTwinkles[twinky].speedy < 0) {
          newLedNum = numLeds-((myTwinkles[twinky].ledNum + ticky)%numLeds);
        } else {
          newLedNum = (myTwinkles[twinky].ledNum + ticky)%numLeds;
        }
    }

    int32_t twinkLength = myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut;

    if ((twinkleTime > (myTwinkles[twinky].start)) && (twinkleTime < (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn))) {
      setLedsFadeIn(newLedNum, twinky, false);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn) > animLength) && (twinkleTime < ((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn) % animLength))) {
      setLedsFadeIn(newLedNum, twinky, true);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if ((twinkleTime >= (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn)) && (twinkleTime < (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy))) {
      setLedsOnFull(newLedNum, twinky, false);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy) > animLength) && (twinkleTime < ((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy) % animLength))) {
      setLedsOnFull(newLedNum, twinky, true);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if ((twinkleTime >= (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy)) && (twinkleTime < (myTwinkles[twinky].start + twinkLength)) ) {
      setLedsFadeOut(newLedNum, twinky, false);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut) > animLength) && (twinkleTime < ((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut) % animLength))) {
      setLedsFadeOut(newLedNum, twinky, true);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if ((twinkleTime >= (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut) % animLength))) && myTwinkles[twinky].hasTwinked) {
      resetTwink(twinky);
    }
  }
}

void setupNewTwinklePattern(int16_t newTwinklePattern) {
  currentLightPattern = newTwinklePattern;
  for (int16_t twink = 0; twink < usedTwinkleCount[currentLightPattern]; twink++) {
    switch (newTwinklePattern) {
      case 0:
        setupTwinkle0(twink);
        break;
      case 1:
        setupTwinkle1(twink);
        break;
      case 2:
        setupTwinkle2(twink);
        break;
      case 3:
        setupTwinkle3(twink);
        break;
      case 4:
        setupTwinkle4(twink);
        break;
      case 5:
        setupTwinkle5(twink);
        break;
      case 6:
        setupTwinkle6(twink);
        break;
      case 7:
        setupTwinkle7(twink);
        break;
      case 8:
        setupTwinkle8(twink);
        break;
      case 9:
        setupTwinkle9(twink);
        break;
      case 10:
        setupTwinkle10(twink);
        break;
      case 11:
        setupTwinkle11(twink);
        break;
      case 12:
        setupTwinkle12(twink);
        break;
      case 13:
        setupTwinkle13(twink);
        break;
    }
  }
}

void resetTwink(int16_t twink) {
  switch (currentLightPattern) {
    case 0:
      setupTwinkle0(twink);
      break;
    case 1:
      setupTwinkle1(twink);
      break;
    case 2:
      setupTwinkle2(twink);
      break;
    case 3:
      setupTwinkle3(twink);
      break;
    case 4:
      setupTwinkle4(twink);
      break;
    case 5:
      setupTwinkle5(twink);
      break;
    case 6:
      setupTwinkle6(twink);
      break;
    case 7:
      setupTwinkle7(twink);
      break;
    case 8:
      setupTwinkle8(twink);
      break;
    case 9:
      setupTwinkle9(twink);
      break;
    case 10:
      setupTwinkle10(twink);
      break;
    case 11:
      setupTwinkle11(twink);
      break;
    case 12:
      setupTwinkle12(twink);
      break;
    case 13:
      setupTwinkle13(twink);
      break;  
    }
}


void setLedsFadeIn(int16_t ledNum, int16_t twinky, bool rolledOver) {

  int32_t percentThroughFade = 0;
  if (rolledOver) {
    percentThroughFade = (((twinkleTime + animLength) - myTwinkles[twinky].start) * 100) / myTwinkles[twinky].fadeIn;
  } else {
    percentThroughFade = ((twinkleTime - myTwinkles[twinky].start) * 100) / myTwinkles[twinky].fadeIn;
  }

  int32_t percentThroughPatternCalc = 0;
  if (rolledOver) {
    percentThroughPatternCalc = ((twinkleTime + animLength) - myTwinkles[twinky].start) * 100;
  } else {
    percentThroughPatternCalc = (twinkleTime - myTwinkles[twinky].start) * 100;
  }
  int32_t percentThroughPattern = percentThroughPatternCalc / (myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut);
  
  int16_t newRed = ((myTwinkles[twinky].rCol + (((myTwinkles[twinky].rToCol - myTwinkles[twinky].rCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;
  int16_t newGreen = ((myTwinkles[twinky].gCol + (((myTwinkles[twinky].gToCol - myTwinkles[twinky].gCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;
  int16_t newBlue = ((myTwinkles[twinky].bCol + (((myTwinkles[twinky].bToCol - myTwinkles[twinky].bCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;
  int16_t newWhite = ((myTwinkles[twinky].wCol + (((myTwinkles[twinky].wToCol - myTwinkles[twinky].wCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;

  if (rgbwLeds[ledNum].r > newRed) { newRed = rgbwLeds[ledNum].r; }
  if (rgbwLeds[ledNum].g > newGreen) { newGreen = rgbwLeds[ledNum].g; }
  if (rgbwLeds[ledNum].b > newBlue) { newBlue = rgbwLeds[ledNum].b; }

  for (int16_t ledToLight = 0; ledToLight < myTwinkles[twinky].widthy; ledToLight++) {
    int16_t minusFade = myTwinkles[twinky].sideFade * ledToLight;
    setLedDirect(ledNum + ledToLight, newRed-minusFade < 0 ? 0 : newRed-minusFade, newGreen-minusFade < 0 ? 0 : newGreen-minusFade, newBlue-minusFade < 0 ? 0 : newBlue-minusFade, newWhite-minusFade < 0 ? 0 : newWhite-minusFade, false);
    setLedDirect(ledNum - ledToLight, newRed-minusFade < 0 ? 0 : newRed-minusFade, newGreen-minusFade < 0 ? 0 : newGreen-minusFade, newBlue-minusFade < 0 ? 0 : newBlue-minusFade, newWhite-minusFade < 0 ? 0 : newWhite-minusFade, false);
  }
}

void setLedsOnFull(int16_t ledNum, int16_t twinky, bool rolledOver) {

  int percentThroughFade = 0;
  if (rolledOver) {
    percentThroughFade = ((twinkleTime + animLength) - myTwinkles[twinky].start) * 100;
  } else {
    percentThroughFade = (twinkleTime - myTwinkles[twinky].start) * 100;
  }
  int32_t percentThroughPattern = percentThroughFade / (myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut);

  int16_t newRed = ((myTwinkles[twinky].rCol + (((myTwinkles[twinky].rToCol - myTwinkles[twinky].rCol) * percentThroughPattern) / 100)));
  int16_t newGreen = ((myTwinkles[twinky].gCol + (((myTwinkles[twinky].gToCol - myTwinkles[twinky].gCol) * percentThroughPattern) / 100)));
  int16_t newBlue = ((myTwinkles[twinky].bCol + (((myTwinkles[twinky].bToCol - myTwinkles[twinky].bCol) * percentThroughPattern) / 100)));
  int16_t newWhite = ((myTwinkles[twinky].wCol + (((myTwinkles[twinky].wToCol - myTwinkles[twinky].wCol) * percentThroughPattern) / 100)));

  if (rgbwLeds[ledNum].r > newRed) { newRed = rgbwLeds[ledNum].r; }
  if (rgbwLeds[ledNum].g > newGreen) { newGreen = rgbwLeds[ledNum].g; }
  if (rgbwLeds[ledNum].b > newBlue) { newBlue = rgbwLeds[ledNum].b; }

  for (int ledToLight = 0; ledToLight < myTwinkles[twinky].widthy; ledToLight++) {
    int16_t minusFade = myTwinkles[twinky].sideFade * ledToLight;
    setLedDirect(ledNum + ledToLight, newRed-minusFade < 0 ? 0 : newRed-minusFade, newGreen-minusFade < 0 ? 0 : newGreen-minusFade, newBlue-minusFade < 0 ? 0 : newBlue-minusFade, newWhite-minusFade < 0 ? 0 : newWhite-minusFade, false);
    setLedDirect(ledNum - ledToLight, newRed-minusFade < 0 ? 0 : newRed-minusFade, newGreen-minusFade < 0 ? 0 : newGreen-minusFade, newBlue-minusFade < 0 ? 0 : newBlue-minusFade, newWhite-minusFade < 0 ? 0 : newWhite-minusFade, false);
  }
}


void setLedsFadeOut(int16_t ledNum, int16_t twinky, bool rolledOver) {
  int32_t percentThroughFade = 0;
  int32_t start = (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy);
  int32_t endy = (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut);
  if (rolledOver) {
    percentThroughFade = 100 - quickAbsolute((((twinkleTime + animLength) - start) * 100) / (endy-start));
  } else {
    percentThroughFade = 100 - quickAbsolute(((twinkleTime - start) * 100) / (endy-start));
  }

  int32_t percentThroughPatternCalc = 0;
  if (rolledOver) {
    percentThroughPatternCalc = ((twinkleTime + animLength) - myTwinkles[twinky].start) * 100;
  } else {
    percentThroughPatternCalc = (twinkleTime - myTwinkles[twinky].start) * 100;
  }
  int32_t percentThroughPattern = (percentThroughPatternCalc / (myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut));

  int16_t newRed = ((myTwinkles[twinky].rCol + (((myTwinkles[twinky].rToCol - myTwinkles[twinky].rCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;
  int16_t newGreen = ((myTwinkles[twinky].gCol + (((myTwinkles[twinky].gToCol - myTwinkles[twinky].gCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;
  int16_t newBlue = ((myTwinkles[twinky].bCol + (((myTwinkles[twinky].bToCol - myTwinkles[twinky].bCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;
  int16_t newWhite = ((myTwinkles[twinky].wCol + (((myTwinkles[twinky].wToCol - myTwinkles[twinky].wCol) * percentThroughPattern) / 100)) * percentThroughFade) / 100;

  if (rgbwLeds[ledNum].r > newRed) { newRed = rgbwLeds[ledNum].r; }
  if (rgbwLeds[ledNum].g > newGreen) { newGreen = rgbwLeds[ledNum].g; }
  if (rgbwLeds[ledNum].b > newBlue) { newBlue = rgbwLeds[ledNum].b; }

  for (int16_t ledToLight = 0; ledToLight < myTwinkles[twinky].widthy; ledToLight++) {
    int16_t minusFade = myTwinkles[twinky].sideFade * ledToLight;
    setLedDirect(ledNum + ledToLight, newRed-minusFade < 0 ? 0 : newRed-minusFade, newGreen-minusFade < 0 ? 0 : newGreen-minusFade, newBlue-minusFade < 0 ? 0 : newBlue-minusFade, newWhite-minusFade < 0 ? 0 : newWhite-minusFade, false);
    setLedDirect(ledNum - ledToLight, newRed-minusFade < 0 ? 0 : newRed-minusFade, newGreen-minusFade < 0 ? 0 : newGreen-minusFade, newBlue-minusFade < 0 ? 0 : newBlue-minusFade, newWhite-minusFade < 0 ? 0 : newWhite-minusFade, false);
  }
}

int findNewStart(int32_t newTwinkleFadeIn) {
  int16_t newRandom = random(1, 32);
  return (animLength32th * newRandom) - newTwinkleFadeIn;
}

int32_t findNewLength() {
  int16_t newRandom = random(1, 30);
  return (animLength32th * newRandom);
}

int32_t findNewShortLength() {
  int16_t newRandom = random(1, 16);
  return (animLength32th * newRandom);
}

void setupTwinkle0(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].rCol = random(240);
  myTwinkles[twinky].gCol = random(140);
  myTwinkles[twinky].bCol = random(220);
  myTwinkles[twinky].wCol = 0;
  myTwinkles[twinky].rToCol = random(240);
  myTwinkles[twinky].gToCol = random(150);
  myTwinkles[twinky].bToCol = random(220);
  myTwinkles[twinky].wToCol = random(100);
  myTwinkles[twinky].lengthy = findNewLength();
  myTwinkles[twinky].fadeIn = 2048;
  myTwinkles[twinky].fadeOut = 2048;
  myTwinkles[twinky].start = findNewStart(myTwinkles[twinky].fadeIn); 
  myTwinkles[twinky].widthy = 1;
  myTwinkles[twinky].speedy = 0;
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}


void setupTwinkle1(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].rCol = random(250);
  myTwinkles[twinky].gCol = random(140);
  myTwinkles[twinky].bCol = random(220);
  myTwinkles[twinky].wCol = 0;
  myTwinkles[twinky].rToCol = random(250);
  myTwinkles[twinky].gToCol = random(150);
  myTwinkles[twinky].bToCol = random(220);
  myTwinkles[twinky].wToCol = 0;
  myTwinkles[twinky].lengthy = 65536;
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = 3;
  myTwinkles[twinky].speedy = 0;
  myTwinkles[twinky].sideFade = 30;
  myTwinkles[twinky].hasTwinked = false;
}

void setupTwinkle2(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].hasTwinked = false;    

  int myRandom = random(3);
  if (myRandom == 0) {
    myTwinkles[twinky].rCol = 255;
    myTwinkles[twinky].gCol = 0;
    myTwinkles[twinky].bCol = 0;
    myTwinkles[twinky].wCol = 100;
    myTwinkles[twinky].rToCol = 100;
    myTwinkles[twinky].gToCol = 0;
    myTwinkles[twinky].bToCol = 0;
    myTwinkles[twinky].wToCol = 0;
    myTwinkles[twinky].lengthy = 65536;
    myTwinkles[twinky].fadeIn = 32768;
    myTwinkles[twinky].fadeOut = 32768;
    myTwinkles[twinky].start = findNewStart(0); 
    myTwinkles[twinky].widthy = 1;
    myTwinkles[twinky].speedy = random(-10, 10);
    myTwinkles[twinky].sideFade = 0;
  } else {
    myTwinkles[twinky].rCol = random(220);
    myTwinkles[twinky].gCol = random(200);
    myTwinkles[twinky].bCol = random(210);
    myTwinkles[twinky].wCol = 0;
    myTwinkles[twinky].rToCol = myTwinkles[twinky].rCol;
    myTwinkles[twinky].gToCol = myTwinkles[twinky].gCol;
    myTwinkles[twinky].bToCol = myTwinkles[twinky].bCol;
    myTwinkles[twinky].wToCol = 0;
    myTwinkles[twinky].lengthy = findNewShortLength();
    myTwinkles[twinky].fadeIn = 0;
    myTwinkles[twinky].fadeOut = 0;
    myTwinkles[twinky].start = findNewStart(0); 
    myTwinkles[twinky].widthy = random(2,6);
    myTwinkles[twinky].speedy = 0;
    myTwinkles[twinky].sideFade = 0;
  }
  
}

void setupTwinkle3(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].rCol = 0;
  myTwinkles[twinky].gCol = 0;
  myTwinkles[twinky].bCol = 0;
  myTwinkles[twinky].wCol = 255;
  myTwinkles[twinky].rToCol = 0;
  myTwinkles[twinky].gToCol = 0;
  myTwinkles[twinky].bToCol = 0;
  myTwinkles[twinky].wToCol = 255;
  myTwinkles[twinky].lengthy = 65536;
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = 1;
  myTwinkles[twinky].speedy = 0;
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}

void setupTwinkle4(int16_t twinky) {
  SetRgbwWheelVars((timey / 90)%256);
  
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].rCol = wheelR;
  myTwinkles[twinky].gCol = wheelG;
  myTwinkles[twinky].bCol = wheelB;
  myTwinkles[twinky].wCol = 0;
  myTwinkles[twinky].rToCol = myTwinkles[twinky].rCol;
  myTwinkles[twinky].gToCol = myTwinkles[twinky].gCol;
  myTwinkles[twinky].bToCol = myTwinkles[twinky].bCol;
  myTwinkles[twinky].wToCol = myTwinkles[twinky].wCol;
  myTwinkles[twinky].lengthy = findNewLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(myTwinkles[twinky].fadeIn); 
  myTwinkles[twinky].widthy = random(3);
  myTwinkles[twinky].speedy = 0;
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}


void setupTwinkle5(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  int myRandom = random(6);
  if (myRandom == 0) {
    myTwinkles[twinky].rCol = 255;
    myTwinkles[twinky].gCol = 0;
    myTwinkles[twinky].bCol = 0;
    myTwinkles[twinky].wCol = 0;    
  } else if (myRandom == 1) {
    myTwinkles[twinky].rCol = 0;
    myTwinkles[twinky].gCol = 255;
    myTwinkles[twinky].bCol = 0;
    myTwinkles[twinky].wCol = 0;
  } else if (myRandom == 2) {
    myTwinkles[twinky].rCol = 0;
    myTwinkles[twinky].gCol = 0;
    myTwinkles[twinky].bCol = 255;
    myTwinkles[twinky].wCol = 0;
  } else {
    myTwinkles[twinky].rCol = 0;
    myTwinkles[twinky].gCol = 0;
    myTwinkles[twinky].bCol = 0;
    myTwinkles[twinky].wCol = 255;
  }
  myTwinkles[twinky].rToCol = myTwinkles[twinky].rCol;
  myTwinkles[twinky].gToCol = myTwinkles[twinky].gCol;
  myTwinkles[twinky].bToCol = myTwinkles[twinky].bCol;
  myTwinkles[twinky].wToCol = myTwinkles[twinky].wCol;
  myTwinkles[twinky].lengthy = findNewLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = 1;
  myTwinkles[twinky].speedy = random(-20, 20);
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}

void setupTwinkle6(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  setGoodRandomColorVars();
  myTwinkles[twinky].rCol = goodColR;
  myTwinkles[twinky].gCol = goodColG;
  myTwinkles[twinky].bCol = goodColB;
  myTwinkles[twinky].wCol = goodColW;
  setGoodRandomColorVars();
  myTwinkles[twinky].rToCol = goodColR;
  myTwinkles[twinky].gToCol = goodColG;
  myTwinkles[twinky].bToCol = goodColB;
  myTwinkles[twinky].wToCol = goodColW;
  myTwinkles[twinky].lengthy = findNewShortLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = random(5,15);
  myTwinkles[twinky].speedy = 0;
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}


void setupTwinkle7(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  setGoodRandomColorVars();
  myTwinkles[twinky].rCol = goodColR;
  myTwinkles[twinky].gCol = goodColG;
  myTwinkles[twinky].bCol = goodColB;
  myTwinkles[twinky].wCol = goodColW;
  setGoodRandomColorVars();
  myTwinkles[twinky].rToCol = goodColR;
  myTwinkles[twinky].gToCol = goodColG;
  myTwinkles[twinky].bToCol = goodColB;
  myTwinkles[twinky].wToCol = goodColW;
  myTwinkles[twinky].lengthy = findNewLength()-16384;
  myTwinkles[twinky].fadeIn = 8192;
  myTwinkles[twinky].fadeOut = 8192;
  myTwinkles[twinky].start = findNewStart(myTwinkles[twinky].fadeIn); 
  myTwinkles[twinky].widthy = 1;
  myTwinkles[twinky].speedy = random(-20, 20);
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}


void setupTwinkle8(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  setGoodRandomColorVars();
  myTwinkles[twinky].rCol = goodColR;
  myTwinkles[twinky].gCol = goodColG;
  myTwinkles[twinky].bCol = goodColB;
  myTwinkles[twinky].wCol = goodColW;
  setGoodRandomColorVars();
  myTwinkles[twinky].rToCol = goodColR;
  myTwinkles[twinky].gToCol = goodColG;
  myTwinkles[twinky].bToCol = goodColB;
  myTwinkles[twinky].wToCol = goodColW;
  myTwinkles[twinky].lengthy = findNewLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = 3;
  int myRandom = random(2);
  if (myRandom == 0) {
    myTwinkles[twinky].speedy = random(3,15);
  } else {
    myTwinkles[twinky].speedy = random(-3,-15);
  }
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}

void setupTwinkle9(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  SetRgbwWheelVars((totalBeats*4)%256);  
  myTwinkles[twinky].rCol = wheelR;
  myTwinkles[twinky].gCol = wheelG;
  myTwinkles[twinky].bCol = wheelB;
  myTwinkles[twinky].wCol = 0;
  myTwinkles[twinky].rToCol = myTwinkles[twinky].rCol;
  myTwinkles[twinky].gToCol = myTwinkles[twinky].gCol;
  myTwinkles[twinky].bToCol = myTwinkles[twinky].bCol;
  myTwinkles[twinky].wToCol = 0;
  myTwinkles[twinky].lengthy = findNewShortLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(myTwinkles[twinky].fadeIn); 
  myTwinkles[twinky].widthy = random(2,6);
  myTwinkles[twinky].speedy = random(-30, 30);
  myTwinkles[twinky].sideFade = 20;
  myTwinkles[twinky].hasTwinked = false;
}

void setupTwinkle10(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].rCol = 0;
  myTwinkles[twinky].gCol = 0;
  myTwinkles[twinky].bCol = 0;
  myTwinkles[twinky].wCol = 255;
  myTwinkles[twinky].rToCol = 0;
  myTwinkles[twinky].gToCol = 0;
  myTwinkles[twinky].bToCol = 0;
  myTwinkles[twinky].wToCol = 255;
  myTwinkles[twinky].lengthy = findNewLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = 1;
  int myRandom = random(2);
  if (myRandom == 0) {
    myTwinkles[twinky].speedy = random(3,15);
  } else {
    myTwinkles[twinky].speedy = random(-3,-15);
  }
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}

void setupTwinkle11(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].rCol = 0;
  myTwinkles[twinky].gCol = 0;
  myTwinkles[twinky].bCol = 0;
  myTwinkles[twinky].wCol = 255;
  setGoodRandomColorVars();
  myTwinkles[twinky].rToCol = goodColR;
  myTwinkles[twinky].gToCol = goodColG;
  myTwinkles[twinky].bToCol = goodColB;
  myTwinkles[twinky].wToCol = goodColW;
  myTwinkles[twinky].lengthy = findNewLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = 1;
  int myRandom = random(3);
  if (myRandom == 0) {
    myTwinkles[twinky].speedy = random(4,14);
  } else if (myRandom == 1) {
    myTwinkles[twinky].speedy = random(-4,-14);
  } else {
    myTwinkles[twinky].speedy = 0;
  }
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}


void setupTwinkle12(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  setGoodRandomColorVars();
  myTwinkles[twinky].rCol = goodColR;
  myTwinkles[twinky].gCol = goodColG;
  myTwinkles[twinky].bCol = goodColB;
  myTwinkles[twinky].wCol = goodColW;
  myTwinkles[twinky].rToCol = myTwinkles[twinky].rCol;
  myTwinkles[twinky].gToCol = myTwinkles[twinky].gCol;
  myTwinkles[twinky].bToCol = myTwinkles[twinky].bCol;
  myTwinkles[twinky].wToCol = myTwinkles[twinky].wCol;
  myTwinkles[twinky].lengthy = findNewLength();
  myTwinkles[twinky].fadeIn = 0;
  myTwinkles[twinky].fadeOut = 0;
  myTwinkles[twinky].start = findNewStart(0); 
  myTwinkles[twinky].widthy = random(10,50);
  int myRandom = random(2);
  if (myRandom == 0) {
    myTwinkles[twinky].speedy = random(4,16);
  } else {
    myTwinkles[twinky].speedy = random(-4,-16);
  }
  myTwinkles[twinky].sideFade = 0;
  myTwinkles[twinky].hasTwinked = false;
}

void setupTwinkle13(int16_t twinky) {
  myTwinkles[twinky].ledNum = random(numLeds);
  myTwinkles[twinky].hasTwinked = false;    

  int myRandom = random(25);
  if (myRandom == 0) {
    myTwinkles[twinky].rCol = 0;
    myTwinkles[twinky].gCol = 0;
    myTwinkles[twinky].bCol = 0;
    myTwinkles[twinky].wCol = 255;
    myTwinkles[twinky].rToCol = 0;
    myTwinkles[twinky].gToCol = 0;
    myTwinkles[twinky].bToCol = 0;
    myTwinkles[twinky].wToCol = 255;
    myTwinkles[twinky].lengthy = findNewShortLength();
    myTwinkles[twinky].fadeIn = 65536;
    myTwinkles[twinky].fadeOut = 65536;
    myTwinkles[twinky].start = findNewStart(65536); 
    myTwinkles[twinky].widthy = 10;
    int myRandom = random(2);
    if (myRandom == 0) {
      myTwinkles[twinky].speedy = random(4,16);
    } else {
      myTwinkles[twinky].speedy = random(-4,-16);
    }
    myTwinkles[twinky].sideFade = 28;
  } else {
    setGoodRandomColorVars();
    myTwinkles[twinky].rCol = goodColR;
    myTwinkles[twinky].gCol = goodColG;
    myTwinkles[twinky].bCol = goodColB;
    myTwinkles[twinky].wCol = goodColW;
    myTwinkles[twinky].rToCol = myTwinkles[twinky].rCol;
    myTwinkles[twinky].gToCol = myTwinkles[twinky].gCol;
    myTwinkles[twinky].bToCol = myTwinkles[twinky].bCol;
    myTwinkles[twinky].wToCol = myTwinkles[twinky].wCol;
    myTwinkles[twinky].lengthy = findNewShortLength();
    myTwinkles[twinky].fadeIn = 0;
    myTwinkles[twinky].fadeOut = 0;
    myTwinkles[twinky].start = findNewStart(0); 
    myTwinkles[twinky].widthy = 1;
    myTwinkles[twinky].speedy = 0;
    myTwinkles[twinky].sideFade = 0;
  }

}

