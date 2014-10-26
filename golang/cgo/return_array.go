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
 * @file return_array.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Oct 26 16:34:45 2014
 *
 **/

package main

/*
#include <stdio.h>
#include <stdlib.h>
static void return_array(char ** buf, int * len) {
  *buf = (char*)malloc(12);
  *buf[0] = 'h';
  *buf[1] = '\0';
  *len = 12;
}
*/
import "C"

import (
	"fmt"
	"unsafe"
)

func returnArray() []byte {
	var l C.int
	var buf *C.char
	C.return_array(&buf, &l)
	defer C.free(unsafe.Pointer(buf))
	return C.GoBytes(unsafe.Pointer(buf), 12)
}

func main() {
	buf := returnArray()
	fmt.Println(len(buf))
	fmt.Println(string(buf))
}
