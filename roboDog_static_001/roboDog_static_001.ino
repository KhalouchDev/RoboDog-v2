#include<Servo.h>

int a = 80;
int b = 80;
int c = 100;

int A_rad;
int B_rad;
int C_rad;

int currentElbow;
int currentShoulder;

int prevShoulder;
int prevElbow;

int smoothedShoulder;
int smoothedElbow;

int shoulderVal;
int kneeVal;

Servo shoulder;
Servo knee;

Servo shoulder1;
Servo knee1;

void setup() {
  shoulder.attach(10);
  knee.attach(9);

  shoulder1.attach(6);
  knee1.attach(5);

  Serial.begin(9600);
}

void loop() {
  /*
  shoulderVal = analogRead(A0);
  kneeVal = analogRead(A1);

  shoulderVal = map(shoulderVal, 0, 1024, 30, 160);
  kneeVal = map(kneeVal, 0, 1024, 0, 180);

  shoulder.write(shoulderVal);
  shoulder1.write(shoulderVal);
  knee.write(kneeVal);
  knee1.write(kneeVal);
  
  Serial.println(shoulderVal);
  Serial.println(kneeVal);*/
  homePos();

}

void homePos(){
  shoulder.write(131);
  shoulder1.write(131);

  knee.write(103);
  knee1.write(103);
}
