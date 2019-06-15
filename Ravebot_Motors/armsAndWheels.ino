/* ************************** ARMS (you can't do much if you've got no arms) ************************** */

bool rightArmUp = false;
bool rightArmDown = false;
bool leftArmUp = false;
bool leftArmDown = false;

void doMyArms() {
  int rightUp = digitalRead(A5);
  int rightDown = digitalRead(A4);
  int leftUp = digitalRead(A2);
  int leftDown = digitalRead(A3);

  // Right arm
  if (rightUp==0 && rightDown==0) {
    sendRArmMotorValue(0);
  } else if (rightUp==0) {
    sendRArmMotorValue(-80);
    delay(100);
    sendRArmMotorValue(0);
    rightArmUp = true;
  } else if (rightDown==0) {
    sendRArmMotorValue(80);
    delay(100);
    sendRArmMotorValue(0);
    rightArmDown = true;
  } else if ((ps2.readButton(PS2_LEFT_2) == 0) && robotSwitchedOn && robotManualMode) {
    if (ps2.readButton(PS2_UP) == 0) {
      sendRArmMotorValue(120);
    } else if (ps2.readButton(PS2_DOWN) == 0) {
      sendRArmMotorValue(-120);
    } else {
      sendRArmMotorValue(0);
    }
  }

  // Left arm
  if (leftUp==0 && leftDown==0) {
    sendLArmMotorValue(0);
  } else if (leftUp==0) {
    sendLArmMotorValue(-80);
    delay(100);
    sendLArmMotorValue(0);
    leftArmUp = true;
  } else if (leftDown==0) {
    sendLArmMotorValue(80);
    delay(100);
    sendLArmMotorValue(0);
    leftArmDown = true;
  } else if ((ps2.readButton(PS2_LEFT_2) == 0) && robotSwitchedOn && robotManualMode) {
    if (ps2.readButton(PS2_TRIANGLE) == 0) {
      sendLArmMotorValue(120);
    } else if (ps2.readButton(PS2_CROSS) == 0) {
      sendLArmMotorValue(-120);
    } else {
      sendLArmMotorValue(0);
    }
  }
}

void moveRArm(int velocity) {
  if (velocity > 0) {
    if (!rightArmUp) {
      sendRArmMotorValue(velocity);
    }
  } else if (velocity < 0) {
    if (!rightArmDown) {
      sendRArmMotorValue(velocity);
    }
  } else {
    sendRArmMotorValue(0);
  }
}

void moveLArm(int velocity) {
  if (velocity < 0) {
    if (!leftArmUp) {
      sendLArmMotorValue(velocity);
    }
  } else if (velocity > 0) {
    if (!leftArmDown) {
      sendLArmMotorValue(velocity);
    }
  } else {
    sendLArmMotorValue(0);
  }
}

int rArmMotorValue = 0;
void sendRArmMotorValue(int newValue) {
  if (newValue != rArmMotorValue)
  {
    rArmMotorValue = newValue;
    ST1.motor(2, rArmMotorValue);
    rightArmUp = false;
    rightArmDown = false;
  }
}

int lArmMotorValue = 0;
void sendLArmMotorValue(int newValue) {
  if (newValue != lArmMotorValue)
  {
    lArmMotorValue = newValue;
    ST1.motor(1, -lArmMotorValue);
    leftArmUp = false;
    leftArmDown = false;
  }
}

/* ************************** WHEELS!! ************************** */

void doMyWheels() {
  
  if (ps2.readButton(PS2_LEFT_2) == 0) {
    
    int readPs2Var=-(ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS)-128)/4;
    sendLWheelMotorValue(readPs2Var);

    readPs2Var=-(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)-128)/4;
    sendRWheelMotorValue(readPs2Var);
    
  } else {
    sendLWheelMotorValue(0);
    sendRWheelMotorValue(0);
  }
}

int rWheelMotorValue = 0;
void sendRWheelMotorValue(int newValue) {
  if (newValue != rWheelMotorValue)
  {
    rWheelMotorValue = newValue;
    ST2.motor(2, rWheelMotorValue);
  }
}

int lWheelMotorValue = 0;
void sendLWheelMotorValue(int newValue) {
  if (newValue != lWheelMotorValue)
  {
    lWheelMotorValue = newValue;
    ST2.motor(1, lWheelMotorValue);
  }
}


