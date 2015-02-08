// Package

package main

import (
    "pe"
    "pe/utils"
    "fmt"
    "os"
    "strconv"
    "math/big"
)

func main() {
    dur := utils.Timeit(pe1)
    fmt.Printf("%d nsec\n", dur.Nanoseconds())
    
    dur = utils.Timeit(pe1b)
    fmt.Printf("%d nsec\n", dur.Nanoseconds())
    
    dur = utils.Timeit(pe2)
    fmt.Printf("%d nsec\n", dur.Nanoseconds())

    dur = utils.Timeit(pe3)
    fmt.Printf("%d nsec\n", dur.Nanoseconds())
}

func pe1() {
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

    ans := pe.Pe1(n)
    fmt.Println("pe1: ", ans)
}

func pe1b() {
    bi := new(big.Int)
    if len(os.Args) > 1 {
        if _, ok := bi.SetString(os.Args[1], 10); !ok {
            fmt.Printf("couldn't interpret line %#v\n", os.Args[1])
        }
    } else {
        bi.SetUint64(uint64(1000))
    }

    //ans := pe.Pe1bloop(bi)
    ans := pe.Pe1b(bi)
    fmt.Println("pe1: ", ans)
}

func pe2() {
    var n uint64
    if len(os.Args) > 1 {
        var err error
        n, err = strconv.ParseUint(os.Args[1], 10, 64)
        if err != nil {
            fmt.Println("failed ParseUint: ", err)
        }
    } else {
        n = 4000000
    }

    for n := range utils.Take(20, pe.Fibonacci()) {
        fmt.Printf("%d ", n)
    }
    fmt.Println("...")

    ans := pe.Pe2(n)
    fmt.Println("pe2: ", ans)
}

func pe3() {
    var n uint64
    if len(os.Args) > 1 {
        var err error
        n, err = strconv.ParseUint(os.Args[1], 10, 64)
        if err != nil {
            fmt.Println("failed ParseUint: ", err)
        }
    } else {
        n = 600851475143
    }

    ans := pe.Pe3(n)
    fmt.Println("pe3: ", ans)
}
