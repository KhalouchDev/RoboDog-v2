#include<Servo.h>

int a = 117;
int b = 117;
float c = 152;

float A;
float B;
float C;

float C_angle;
float B_angle;

Servo shoulder;
Servo knee;

void setup() {
  shoulder.attach(11);
  knee.attach(10);
}

void loop() {
  kinematics();
}
