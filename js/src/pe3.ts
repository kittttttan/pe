import {Primality} from './primality';

export class Pe3 {
  public static solve(n = 600851475143): number[] {
    return Primality.divisors(n);
  }
}
