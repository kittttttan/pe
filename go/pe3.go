package main

import (
  "./lib"

  "fmt"
  "os"
  "strconv"
  "time"
)

func pe3(n uint64) []uint64 {
  return pe.Divisors(n)
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
    n = 600851475143
  }

  start := time.Now()
  ans := pe3(n)
  end := time.Now()

  fmt.Println("pe3: ", ans)
  fmt.Printf("%f sec",(end.Sub(start)).Seconds())
}
