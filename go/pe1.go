package main

import (
    "fmt"
    "os"
    "strconv"
)

func sumx2(n uint64) uint64 {
    return n * (n + 1)
}

func pe1(n uint64) uint64 {
    return (3 * sumx2(n / 3) + 5 * sumx2(n / 5) - 15 * sumx2(n / 15)) / 2
}

func pe1loop(n uint64) uint64 {
    var sum uint64 = 0
    for i := uint64(1); i <= n; i++ {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i
        }
    }
    
    return sum
}

func main() {
    var n uint64
    if len(os.Args) > 1 {
        var err error
        n, err = strconv.ParseUint(os.Args[1], 10, 64)
        if err != nil {
            fmt.Println("failed ParseUint: ", err)
        }
    } else {
        n = 1000
    }
    
    ans := pe1(n)
    fmt.Println("pe1: ", ans)
}
