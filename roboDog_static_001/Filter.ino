// to smooth motion
int filter(int prev, int current) {
  int filter = (current * 0.05) + (prev * 0.95);
  return filter;
}
