int gcd(int x, int y) {
  // starting with the smallest possible GCD
  int gcd = 1;

  for (int i = 1; i <= x && i <= y; i++) {
    if (x % i == 0 && y % i == 0) {
      // update gcd to the current number if it divides both
      gcd = i;
    }
  }
  return gcd;
}
