#include<Servo.h>

int a = 8;
int b = 8;
float c;

float A;
float B;
float C;

Servo shoulder;
Servo knee;

void setup() {
  shoulder.attach(10);
  knee.attach(9);
}

void loop() {
  kinematics();
}
