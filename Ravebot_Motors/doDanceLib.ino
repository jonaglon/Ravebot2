/*  
2 - L claw
3 - l wrist ud
4 - R elbow
5 - R wrist lr
6 - R claw increase to grab
7 - r wrist ud
8 - l elbow
9 - l wrist lr

10 - l new nod
11 - l new tilt
12 - l new shake  */

int numDances = 2;
int currentDance = 1;

/* ************** Dance Move Functions - Called Every Cycle ********************* */
void doDancing() {
  if (currentDance == 1)
    dance1Movements();
   else if (currentDance == 2)
    dance2Movements();
    
}

/* ************* Dance BEAT moves called by beat signal from the Due *************** */
void doBeatDanceMove() {
  if (robotManualMode || !robotSwitchedOn)
    return;

  if (currentDance == 1)
    doDance1BeatMoves();
  else if (currentDance == 2)
    doDance2BeatMoves();
}

void changeDance() {
  int newDanceNumber;
  
  while (newDanceNumber != currentDance)
    newDanceNumber = random(1, numDances);
    
  currentDance = newDanceNumber;
  sendDanceNumberToLights(currentDance);
}

/* ******************************************* Constant Dance Functions *************************** */

void moveLeftWristLR (bool moveLeft, int delayo) {
  int doLeftMove = moveLeft ? -1 : 1;
  moveServoSoft(9, doLeftMove, delayo);
}

void moveRightWristLR (bool moveLeft, int delayo) {
  int doLeftMove = moveLeft ? -1 : 1;
  moveServoSoft(5, doLeftMove, delayo);
}

void moveLeftWristUD (bool moveLeft, int delayo) {
  int doLeftMove = moveLeft ? -1 : 1;
  moveServoSoft(3, doLeftMove, delayo);
}

void moveRightWristUD (bool moveLeft, int delayo) {
  int doLeftMove = moveLeft ? -1 : 1;
  moveServoSoft(7, doLeftMove, delayo);
}

void moveLeftClaw (bool moveLeft, int delayo) {
  int doLeftMove = moveLeft ? -1 : 1;
  moveServoSoft(2, doLeftMove, delayo);
}

void moveRightClaw (bool moveLeft, int delayo) {
  int doLeftMove = moveLeft ? -1 : 1;
  moveServoSoft(6, doLeftMove, delayo);
}

void shakeHead (bool shakeLeft, int delayo) {
  int doLeftMove = shakeLeft ? -1 : 1;
  moveServoSoft(12, doLeftMove, delayo);
}

void tiltHead (bool tiltLeft, int delayo) {
  int doLeftMove = tiltLeft ? -1 : 1;
  moveServoSoft(11, doLeftMove, delayo);
  
}


/************************** Dance beat move functions **************************/
void openCloseClaw(int speedy) {
  if ((currentBeat % 4) == 0) {
    leftClaw (false, speedy);
    rightClaw (false, speedy);
  } else if ((currentBeat % 4) == 2) {
    leftClaw (true, speedy);
    rightClaw (true, speedy);
  }
}


void leftWristLR (bool moveLeft) {
  if (moveLeft)
    moveServoToPos(9, servos[9].leftDancePos);
  else
    moveServoToPos(9, servos[9].rightDancePos);
}

void rightWristLR (bool moveLeft) {
  if (moveLeft)
    moveServoToPos(5, servos[5].leftDancePos);
  else
    moveServoToPos(5, servos[5].rightDancePos);
}

void leftWristUD (bool moveLeft) {
  if (moveLeft)
    moveServoToPos(3, servos[3].leftDancePos);
  else
    moveServoToPos(3, servos[3].rightDancePos);
}

void rightWristUD (bool moveLeft) {
  if (moveLeft)
    moveServoToPos(7, servos[7].leftDancePos);
  else
    moveServoToPos(7, servos[7].rightDancePos);
}

void leftClaw (bool moveLeft, int delayo) {
  if (moveLeft)
    moveServoToPos(2, servos[2].leftDancePos);
  else
    moveServoToPos(2, servos[2].rightDancePos);
}

void rightClaw (bool moveLeft, int delayo) {
  if (moveLeft)
    moveServoToPos(6, servos[6].leftDancePos);
  else
    moveServoToPos(6, servos[6].rightDancePos);
}

void beatShake (bool moveLeft, int delayo) {
  if (moveLeft)
    moveServoToPos(12, servos[12].leftDancePos);
  else
    moveServoToPos(12, servos[12].rightDancePos);
}


void nodHead(bool headUp) {
  if (headUp) {
    moveServoToPos(10, servos[10].rightDancePos);
  } else {
    moveServoToPos(10, servos[10].leftDancePos);
  }
}

void rightArmUpRightElbowUp() {
  moveServoToPos(4, rightArmUpRightElbowUpPos);
}
void rightArmUpRightElbowDown() {
  moveServoToPos(4, rightArmUpRightElbowDownPos);
}

void leftArmUpLeftElbowUp() {
  moveServoToPos(8, leftArmUpLeftElbowUpPos);
}
void leftArmUpLeftElbowDown() {
  moveServoToPos(8, leftArmUpLeftElbowDownPos);
}

void rightArmDownRightElbowUp() {
  moveServoToPos(4, rightArmDownRightElbowUpPos);
}
void rightArmDownRightElbowDown() {
  moveServoToPos(4, rightArmDownRightElbowDownPos);
}

void leftArmDownLeftElbowUp() {
  moveServoToPos(8, leftArmDownLeftElbowUpPos);
}
void leftArmDownLeftElbowDown() {
  moveServoToPos(8, leftArmDownLeftElbowDownPos);
}



