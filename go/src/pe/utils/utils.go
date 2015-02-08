// Package implements helper functions

package utils

func Take(n int, in <-chan int) <-chan int {
    out := make(chan int, n)
    go func() {
        for i, num := 0, <-in; i < n; i, num = i + 1, <-in { out <- num }
        close(out)
    }()
    return out
}

func Filter(f func (int) bool, in <- chan int) <-chan int {
    ch := make(chan int)
    go func() {
        for n := range in {
            if f(n) { ch <- n }
        }
        close(ch)
    }()
    return ch
}
