package pe

func Pe2(limit uint64) uint64 {
    var (
        a uint64 = 1
        b uint64 = 2
        s uint64 = 2
    )

    for b <= limit {
        a, b = b, a + b
        if (b & 1) == 0 {
            s += b
        }
    }

    return s
}

func fib(ch chan int) {
    for i, j := 0, 1; ; i, j = i + j, i {
        ch <- i
    }
}

func Fibonacci() <-chan int {
    ch := make(chan int)
    go fib(ch)
    return ch
}