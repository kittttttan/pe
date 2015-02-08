package pe_test

import (
    "."
    "pe/primes"
    "pe/utils"
    "math/big"
    "testing"
)

func TestPe1b(t *testing.T) {
    bi := new(big.Int)
    bi.SetUint64(uint64(1000))

    actual := pe.Pe1b(bi)
    expected := new(big.Int).SetUint64(uint64(234168))

    if actual.Cmp(expected) != 0 {
        t.Errorf("got %v, want %v", actual, expected)
    }
}

func BenchmarkPe1b(b *testing.B) {
    bi := new(big.Int)
    bi.SetUint64(uint64(1000000))
    for i := 0; i < b.N; i++ {
        pe.Pe1b(bi)
    }
}

func TestPe1bloop(t *testing.T) {
    bi := new(big.Int)
    bi.SetUint64(uint64(1000))

    actual := pe.Pe1bloop(bi)
    expected := new(big.Int).SetUint64(uint64(234168))

    if actual.Cmp(expected) != 0 {
        t.Errorf("got %v, want %v", actual, expected)
    }
}

func BenchmarkPe1bloop(b *testing.B) {
    bi := new(big.Int)
    bi.SetUint64(uint64(1000000))
    for i := 0; i < b.N; i++ {
        pe.Pe1bloop(bi)
    }
}

func TestPrimes(t *testing.T) {
    actual := utils.Take(10, primes.Primes())
    expected := []int{
        2,3,5,7,11,13,17,19,23,29,
    }
    i := 0
    for p := range actual {
        if p != expected[i] {
            t.Errorf("failed Primes[%d]: got %v, want %v", i, p, expected[i])
        }
        i = i + 1
    }
}

func BenchmarkPrimes(b *testing.B) {
    for i := 0; i < b.N; i++ {
        utils.Take(100, primes.Primes())
    }
}
