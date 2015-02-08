// Package implements timeit in Python like function

package utils

import (
  "time"
  "reflect"
)

type Any interface{}

func Timeit(f Any, args... Any) time.Duration {
    fv := reflect.ValueOf(f)
    if fv.Kind() != reflect.Func {
        panic("f must be func.")
    }
    inputs := make([]reflect.Value, len(args))
    for i, _ := range args {
        inputs[i] = reflect.ValueOf(args[i])
    }
    start := time.Now()
    fv.Call(inputs)

    return time.Since(start)
}
