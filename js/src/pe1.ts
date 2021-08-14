export class Pe1 {
  public static solveLoop(limit = 1000): number {
    let s = 0;
    for (let i = 1; i < limit + 1; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        s += i;
      }
    }
    return s;
  }

  public static solve(n = 1000): number {
    let s = 0;

    if (n > 2) {
      const n3 = n / 3 | 0;
      const n5 = n / 5 | 0;
      const n15 = n / 15 | 0;
      s = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) >> 1;
    }

    return s;
  }
}
