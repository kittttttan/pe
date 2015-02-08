package pe

import (
    "math/big"
)

func sumx2b(n *big.Int) *big.Int {
    t := new(big.Int)
    return t.Mul(n, t.Add(n, big.NewInt(1)))
}

func Pe1b(n *big.Int) *big.Int {
    i2 := big.NewInt(2)
    i3 := big.NewInt(3)
    i5 := big.NewInt(5)
    i15 := big.NewInt(15)

    s3 := new(big.Int)
    s3.Mul(i3, sumx2b(s3.Div(n, i3)))

    s5 := new(big.Int)
    s5.Mul(i5, sumx2b(s5.Div(n, i5)))

    s15 := new(big.Int)
    s15.Mul(i15, sumx2b(s15.Div(n, i15)))

    t := new(big.Int)
    t.Add(s3, s5)
    t.Sub(t, s15)
    t.Div(t, i2)

    return t
}

func Pe1bloop(n *big.Int) *big.Int {
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
