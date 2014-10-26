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
 * @file passing_array.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Oct 26 16:07:47 2014
 *
 **/

package main

/*
#include <stdio.h>
static void print_array(void * buf, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    printf("%c", ((char*)buf)[i]);
  }
  printf("\n");
}
*/
import "C"

import (
	_ "fmt"
	"unsafe"
)

func printArray(buf []byte) {
	C.print_array(unsafe.Pointer(&buf[0]), C.size_t(len(buf)))
}

func main() {
	printArray([]byte("hello, world!"))
}
