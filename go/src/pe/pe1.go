package pe

func sumx2(n uint64) uint64 {
    return n * (n + 1)
}

func Pe1(n uint64) uint64 {
    return (3 * sumx2(n / 3) + 5 * sumx2(n / 5) - 15 * sumx2(n / 15)) / 2
}

func Pe1loop(n uint64) uint64 {
    var sum uint64 = 0
    for i := uint64(1); i <= n; i++ {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i
        }
    }
    
    return sum
}
