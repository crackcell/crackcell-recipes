/* -*- encoding: utf-8; indent-tabs-mode: t -*- */

/***************************************************************
 *
 * Copyright (c) 2014, Menglong TAN <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 *
 *
 * @file test.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Sep 12 11:49:46 2014
 *
 **/

package main

import (
	"fmt"
	"reflect"
)

type Inter interface {
	Dummy()
}

type MyStruct struct {
	name string
}

func (this MyStruct) Dummy() {}

func (this MyStruct) GetName() (string, int) {
	return this.name, 1
}

func call(s Inter, m string) {
	fmt.Println(reflect.TypeOf(s))
	values := reflect.ValueOf(s).MethodByName(m).Call([]reflect.Value{})
	fmt.Println(reflect.TypeOf(values[0].Interface()))
	fmt.Println(values[0].String())
}

func main() {
	s := "hello world"
	fmt.Println(reflect.TypeOf(s))
	fmt.Println(reflect.ValueOf(s))

	call(MyStruct{name: "crackcell"}, "GetName")
}
