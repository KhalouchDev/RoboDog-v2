int kinematics(int leg) {
  C_rad = (sq(a) + sq(b) - sq(c)) / (2*a*b);
  C_rad = acos(C_rad);  //radians
  B_rad = PI - (C_rad * 2); //radians

  // convert radians to degrees
  currentElbow = C_rad * (180/PI); //degrees
  currentShoulder = B_rad * (180/PI); //degrees

  if(leg == 0)
  {currentShoulder = map(currentShoulder, 0, 180, 160, 30);
  currentElbow = map(currentElbow, 0, 180, 0, 360);}
  else if(leg == 1){
    currentShoulder = map(currentShoulder, 0, 180, 30, 160);
    currentElbow = map(currentElbow, 0, 180, 0, 360);
  }
/*
  smoothedShoulder = filter(prevShoulder, currentShoulder);
  smoothedElbow = filter(prevElbow, currentElbow);

  prevShoulder = smoothedShoulder;
  prevElbow = smoothedElbow;
  */
  Serial.print(currentShoulder);
  Serial.print(", ");
  Serial.print(currentElbow);
  Serial.println();
  
  /*
  shoulder.write(currentShoulder);
  knee.write(currentElbow);

  shoulder1.write(currentShoulder);
  knee1.write(currentElbow);
  */
  return currentShoulder;
}
