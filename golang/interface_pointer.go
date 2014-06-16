/* -*- encoding: utf-8; indent-tabs-mode: t -*- */

/***************************************************************
 *
 * Copyright (c) 2014, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 *
 *
 * @file interface_pointer.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Mon Jun 16 18:04:53 2014
 *
 **/

package main

import "fmt"

type Interface1 interface {
	Method1()
}

type Imp1 struct{}

func (p *Imp1) Method1() {
	fmt.Println("Method1 from Imp1")
}

func main() {
	var imp1 Imp1
	imp1.Method1()
	var iter1 Interface1
	iter1 = imp1
	iter1.Method1()
}
