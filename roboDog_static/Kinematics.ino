void kinematics() {
  C = (sq(a) + sq(b) - sq(c)) / (2*a*b);
  C = acos(C);  //radians
  B = PI - (C * 2); //radians

  // convert radians to degrees
  C_angle = C * (180/PI); //degrees
  B_angle = B * (180/PI); //degrees

  shoulder.write(B);
  knee.write(C);
}
