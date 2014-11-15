package main

import (
  "fmt"
  "os"
  "strconv"
)

func pe2(limit uint64) uint64 {
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

func main() {
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

  ans := pe2(n)
  fmt.Println("pe2: ", ans)
}
