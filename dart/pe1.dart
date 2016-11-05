class Pe1 {
  static int solveLoop([int limit = 1000]) {
    int s = 0;
    for (int i = 1; i < limit + 1; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        s += i;
      }
    }
    return s;
  }

  static int solve([int n = 1000]) {
    int s = 0;

    if (n > 2) {
      final int n3 = n ~/ 3;
      final int n5 = n ~/ 5;
      final int n15 = n ~/ 15;
      s = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) >> 1;
    }

    return s;
  }
}
