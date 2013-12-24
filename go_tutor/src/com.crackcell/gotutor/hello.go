/* -*- encoding: utf-8; indent-tabs-mode: t -*- */

package main

import "fmt"

func add(a int, b int) (int) {
  return a + b
}

func main() {
	fmt.Printf("hello 世界\n")
  sum := add(1, 2)
  fmt.Printf("%d\n", sum)
  add2 := func(a int, b int) (int) {
    return a + b
  }
  fmt.Printf("%d\n", add2(1, 2))
}
