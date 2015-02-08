package primes_test

import (
    "pe/primes"
    "pe/utils"
    "testing"
)

func TestPrimes(t *testing.T) {
    expected := []int{
        2,3,5,7,11,13,17,19,23,29,
        31,37,41,43,47,53,59,61,67,71,
        73,79,83,89,97,101,103,107,109,113,
    }
    actual := utils.Take(len(expected), primes.Primes())

    i := 0
    for p := range actual {
        if p != expected[i] {
            t.Errorf("failed Primes[%d]: got %v, want %v", i, p, expected[i])
        }
        i = i + 1
    }
}

func TestFilteredPrimes(t *testing.T) {
    expected := []int{
        101,103,107,109,
    }
    fn := func(n int) bool { return 100 < n && n < 110 }
    actual := utils.Filter(fn, utils.Take(100, primes.Primes()))

    i := 0
    for p := range actual {
        if p != expected[i] {
            t.Errorf("Primes[%d]: got %v, want %v", i, p, expected[i])
        }
        i = i + 1
    }

    if i != len(expected) {
        t.Errorf("length: got %d, want %d", i, len(expected))
    }
}