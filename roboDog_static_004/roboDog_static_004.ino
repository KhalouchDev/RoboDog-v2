#include<Servo.h>

Servo shoulder1;
Servo shoulder2;
Servo shoulder3;
Servo shoulder4;

Servo knee1;
Servo knee2;
Servo knee3;
Servo knee4;

int currentMillis;
int prevMillis;

int stepFlag;
int currentStepMillis;

void setup(){
  // leg 1
  shoulder1.attach(11);
  knee1.attach(10);
  //leg 2
  shoulder2.write(9);
  knee2.attach(6);
  //leg 3
  shoulder3.attach(5);
  knee3.attach(3);
  // leg 4
  shoulder4.attach(A0);
  knee4.attach(A1);
  
  stepFlag = 1;
  
  Serial.begin(9600);
}

void loop(){
  if(stepFlag == 1){
    Serial.println("Step 1");
    homePos();
    delay(1000);
    stepFlag = 2;
  }
  else if(stepFlag == 2){
    for(int i=50; i>0; i--){
      knee1.write(i);
      knee2.write(i);
      int i_inv = map(i, 50, 0, 180, 130);
      knee3.write(i_inv);
      knee4.write(i_inv);
      delay(100);
    }
    delay(1000);
    stepFlag = 3;
  }
  else if(stepFlag = 3){
    for(int a; a<50; a++){
      knee1.write(a);
      knee2.write(a);
      int a_inv = map(a, 0, 50, 130, 180);
      knee3.write(a_inv);
      knee4.write(a_inv);
      delay(100);
    }
    delay(1000);
    stepFlag = 2;
  }
  
}
/*
int smoothing(int prev, int current){
  int filter = (current * 0.05) + (prev * 0.95);
  return filter;
}
*/

void homePos(){
  // leg 1 and 2
  shoulder1.write(50);
  knee1.write(50);
  shoulder2.write(50);
  knee2.write(50);

  // leg 3 and 4
  shoulder4.write(130);
  knee4.write(130);
  shoulder3.write(130);
  knee3.write(130);
}
