package main

import (
    "fmt"
    "os"
    "math/big"
)

func sumx2(n *big.Int) *big.Int {
    t := new(big.Int)
    return t.Mul(n, t.Add(n, big.NewInt(1)))
}

func pe1(n *big.Int) *big.Int {
    i2 := big.NewInt(2)
    i3 := big.NewInt(3)
    i5 := big.NewInt(5)
    i15 := big.NewInt(15)

    s3 := new(big.Int)
    s3.Mul(i3, sumx2(s3.Div(n, i3)))

    s5 := new(big.Int)
    s5.Mul(i5, sumx2(s5.Div(n, i5)))

    s15 := new(big.Int)
    s15.Mul(i15, sumx2(s15.Div(n, i15)))

    t := new(big.Int)
    t.Add(s3, s5)
    t.Sub(t, s15)
    t.Div(t, i2)

    return t
}

func pe1loop(n *big.Int) *big.Int {
    sum := big.NewInt(0)
    t := big.NewInt(0)
    i := big.NewInt(1)
    for {
        if t.Mod(i, big.NewInt(3)).Sign() == 0 ||
                t.Mod(i, big.NewInt(5)).Sign() == 0 {
            sum.Add(sum, i)
        }
        if i.Cmp(n) > 0 {
            break
        }
        i.Add(i, big.NewInt(1))
    }
    
    return sum
}

func main() {
    bi := new(big.Int)
    if len(os.Args) > 1 {
        if _, ok := bi.SetString(os.Args[1], 10); !ok {
            fmt.Printf("couldn't interpret line %#v\n", os.Args[1])
        }
    } else {
        bi.SetUint64(uint64(1000))
    }
    fmt.Println("bi = ", bi)

    //ans := pe1loop(bi)
    ans := pe1(bi)
    fmt.Println("pe1: ", ans)
}
