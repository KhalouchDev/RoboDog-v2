void kinematics() {
  C = (sq(a) + sq(b) - sq(c)) / (2*a*b);
  C = acos(C);
  C = (C * 180 / PI);

  B = A = ((180-C)/2);

  shoulder.write(B);
  knee.write(C);
}
