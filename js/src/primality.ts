export class Primality {
  protected static primes: number[] = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
  ];

  public static get(i: number): number {
    while (i >= this.primes.length) {
      this.next();
    }
    return this.primes[i];
  }

  public static next(): number {
    let n: number = this.primes[this.primes.length - 1] + 2;
    while (!this.isPrime(n)) {
      n += 2;
    }
    this.primes.push(n);
    return n;
  }

  private static isPrime(n: number): boolean {
    let sqrtn: number = Math.floor(Math.sqrt(n));
    for (let p of this.primes) {
      if (p > sqrtn) {
        return true;
      }
      if (n % p === 0) {
        return false;
      }
    }
    return true;
  }

  public static divisors(n: number): number[] {
    const p: number[] = [];
    if (n === 0) {
      return p;
    }
    if (!Number.isInteger(n)) {
      return p;
    }
    n = Math.abs(n);
    let pIndex: number = 0;
    while (n > 1) {
      while (n % this.get(pIndex) === 0) {
        p.push(this.get(pIndex));
        n /= this.get(pIndex);
      }
      ++pIndex;
    }

    return p;
  }
}
