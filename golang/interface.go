package main

import (
	"fmt"
)

type Interface1 interface {
	Interface2
	Method1() int32
	Method2() int32
}

type Interface2 interface {
	Method3() int32
}

type Imp1 struct {
}

func (this Imp1) Method1() int32 {
	fmt.Println("Method1")
	return 1
}

func (this Imp1) Method2() int32 {
	fmt.Println("Method2")
	return 1
}

type Imp2 struct {
}

func (this Imp2) Method3() int32 {
	fmt.Println("Method3")
	return 1
}

func (this Imp1) Method3() int32 {
	fmt.Println("Method3")
	return 1
}

func doit(inter Interface1) {
	inter.Method1()
}

func main() {
	var imp1 Imp1
	var inter Interface1
	inter = Interface1(imp1)
	doit(inter)
}
