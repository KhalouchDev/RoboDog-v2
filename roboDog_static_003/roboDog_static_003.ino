#include<Servo.h>

Servo shoulder1;
Servo shoulder2;
Servo shoulder3;
Servo shoulder4;

Servo knee1;
Servo knee2;
Servo knee3;
Servo knee4;

int shoulder1Prev;
int shoulder2Prev;
int shoulder3Prev;
int shoulder4Prev;
int knee1Prev;
int knee2Prev;
int knee3Prev;
int knee4Prev;

int shoulder1Current;
int shoulder2Current;
int shoulder3Current;
int shoulder4Current;
int knee1Current;
int knee2Current;
int knee3Current;
int knee4Current;

int shoulder1Smoothed;
int shoulder2Smoothed;
int shoulder3Smoothed;
int shoulder4Smoothed;
int knee1Smoothed;
int knee2Smoothed;
int knee3Smoothed;
int knee4Smoothed;

int currentMillis;
int prevMillis;

int stepFlag;
int currentStepMillis;

int pot;

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
    knee1.write(0);
    delay(500);
    knee1.write(50);
    delay(500);
    stepFlag = 3;
  }
  else if(stepFlag == 3){
    knee2.write(0);
    delay(500);
    knee2.write(50);
    delay(500);
    stepFlag = 4;
  }
  else if(stepFlag == 4){
    knee3.write(180);
    delay(500);
    knee3.write(130);
    delay(500);
    stepFlag = 5;
  }
  else if(stepFlag == 5){
    knee4.write(180);
    delay(500);
    knee4.write(130);
    delay(500);
    stepFlag = 1;
  }
  /*
  else if(stepFlag == 2){
    Serial.println("Step 2");
    // leg one walk
    knee1.write(0);
    delay(200);
    shoulder1.write(120);
    delay(200);
    knee1.write(120);
    delay(500);
    stepFlag = 3;
    
  }
  else if(stepFlag == 3){
    Serial.println("Step 3");
    // leg four walk
    knee4.write(180);
    delay(200);
    shoulder4.write(60);
    delay(200);
    knee4.write(60);
    delay(500);
    
    stepFlag = 4;
  }
  else if(stepFlag == 4){
    Serial.println("Step 4");
    // leg 1 and 4 back to home
    //leg 1
    shoulder1.write(50);
    knee1.write(50);

    // leg 4
    shoulder4.write(130);
    knee4.write(130);

    stepFlag = 5;
  }
  else if(stepFlag == 5){
    Serial.println("Step 5");
    // leg 2 walk
    knee2.write(0);
    delay(200);
    shoulder2.write(120);
    delay(200);
    knee2.write(120);

    stepFlag = 6;
  }
  else if(stepFlag == 6){
    Serial.println("Step 6");
    knee3.write(180);
    delay(200);
    shoulder3.write(60);
    delay(200);
    knee3.write(60);
    delay(500);

    stepFlag = 1;
  }
  */
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

  // leg 3 and 4
  shoulder4.write(130);
  knee4.write(130);
}
