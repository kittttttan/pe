export class Pe2 {
  public static solve(n: number = 4000000): number {
    let [a, b, s]: number[] = [1, 2, 2];
    while (b <= n) {
      [a, b] = [b, a + b];
      if ((b & 1) === 0) {
        s += b;
      }
    }
    return s;
  }
}
