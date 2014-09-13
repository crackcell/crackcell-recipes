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
 * @file variadic_parameter.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sat Sep 13 16:45:30 2014
 *
 **/

package main

import (
	"fmt"
)

func test(args ...interface{}) {
	fmt.Println(args)
}

func main() {
	var a []interface{}
	a = []interface{}{1, 2, 3, 4}
	test(a...)
	test(a)
}
