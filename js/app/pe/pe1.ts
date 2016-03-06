export class Pe1 {
  public static pe1a(limit: number = 1000): number {
    let s: number = 0;
    for (let i: number = 1; i < limit + 1; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        s += i;
      }
    }
    return s;
  }

  public static pe1(n: number = 1000): number {
    let s: number = 0;

    if (n > 2) {
      const n3: number = n / 3;
      const n5: number = n / 5;
      const n15: number = n / 15;
      s = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) >> 1;
    }

    return s;
  }
}
