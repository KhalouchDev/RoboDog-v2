#include<Servo.h>
#include<Ramp.h>

Servo shoulder1;
Servo elbow1;

// defualt position
int shoulder1Offset = 000;
int elbow1Offset = 000;

// moving the foot forwards or backwards in the side plane
float shoulderAngle2;
float shoulderAngle2a;
float shoulderAngle2Degrees;
float shoulderAngle2aDegrees;
float z2;
float x;

// sode plane of individial leg only
#define lowerLength 80
#define upperLength 80
float armLength;
float z;
float shoulderAngle1;
float shoulderAngleDegrees;
float shoulderAngle1a;
float elbowAngle;
float elbowAngleDegrees;

// interpolation targets
float zTarget;
float xTarget;

// output scaling
float shoulderMs;
float shoulderMs2;
float elbowMs;

unsigned long currentMillis;
unsigned long previousMillis;

// step sequence setup
long previousStepMillis = 0;
int stepFlag = 0;

//------------------------

class Interpolation {
  public:
    rampInt myRamp;
    int interpolationFlag = 0;
    int savedValue;

    int go(int input, int duration) {
      if(input != savedValue){ // check for new data
        interpolationFlag = 0;
      }
      savedValue = input; // bookmark the old value

      if(interpolationFlag == 0){
        myRamp.go(input, duration, LINEAR, ONCEFORWARD);
        interpolationFlag = 1;
      }

      int output = myRamp.update();
      return output;
    }
}; // end of class

// interpolation objects
Interpolation interpX;
Interpolation interpZ;

void setup() {
  shoulder1.attach(11);
  elbow1.attach(10);

  shoulder1.writeMicroseconds(shoulder1Offset);
  elbow1.writeMicroseconds(elbow1Offset);

  // set default position for arm
  zTarget = 000;
  xTarget = 000;

  Serial.begin(9600);
}

void loop() {
  currentMillis = millis();

  if(currentMillis - previousMillis >= 10){ // start timed loop
    previousMillis = currentMillis;

    // step sequencer
    if(stepFlag == 0){
      stepFlag = 1;
    }
    if(stepFlag == 1 && currentMillis - previousMillis >= 1000){
      //zTarget = 000;
      //xTarget = 000;
      previousStepMillis = currentMillis;
      stepFlag = 2;
    }
    else if(stepFlag == 2 && currentMillis - previousMillis >= 1200){
      //zTarget = 000;
      //xTarget = 000;
      previousStepMillis = currentMillis;
      stepFlag = 3;
    }
    else if(stepFlag == 3 && currentMillis - previousMillis >= 1000){
      //zTarget = 000;
      //xTarget = 000;
      previousStepMillis = currentMillis;
      stepFlag = 4;
    } //add more steps if needed
    // end of step sequence

    // start inerpolation

    z = interpZ.go(zTarget, 1000);
    x = interpX.go(xTarget, 1000);

    // *** Inverse Kinematics ***

    // calculate modification to shoulder angle and arm length
    shoulderAngle2a = atan(z/x);
    shoulderAngle2aDegrees = shoulderAngle2a * (180/PI); // degrees
    shoulderAngle2 = shoulderAngle2a - 000; // take the defult offset (in radians)
    shoulderAngle2Degrees = shoulderAngle2 * (180/PI); // degrees
    shoulderMs2 = shoulderAngle2Degrees * 11;

    z2 = x/cos(shoulderAngle2a); // calc new arm length to feed to the next bit of code

    //***********

    // calculate arm length base on upper/lower length and elbow and shoulder angle
    shoulderAngle1a = (sq(upperLength) + sq(z2) - sq(lowerLength)) / (2 * upperLength * z2);
    shoulderAngle1 = acos(shoulderAngle1a); // radians
    elbowAngle = PI - (shoulderAngle1 * 2); // radians

    // calculate degrees from angles
    shoulderAngleDegrees = shoulderAngle1 * (180/PI); // degrees
    elbowAngleDegrees = elbowAngle * (180/PI); // degrees

    // calculate milliseconds PWM to drive the servo
    shoulderMs = shoulderAngleDegrees * 11;
    elbowMs = elbowAngleDegrees * 11;

    // *** End of Inverse Kinematics ***
    shoulder1.writeMicroseconds(shoulder1Offset - (shoulderMs - 480) - shoulderMs2); // shoulder
    elbow1.writeMicroseconds(elbow1Offset + (elbowMs - 1000)); // elbow     
  } // end of timed loop
} // end of main loop
