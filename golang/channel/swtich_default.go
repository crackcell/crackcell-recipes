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
 * @file swtich_default.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Mon Oct 13 10:36:24 2014
 *
 **/

package main

import (
	"fmt"
	"time"
)

//===================================================================
// Public APIs
//===================================================================

//===================================================================
// Private
//===================================================================

func main() {
	ch1 := make(chan int)
	ch2 := make(chan int)
	go func() {
		//for {
		time.Sleep(1000)
		ch1 <- 1
		close(ch1)
		//}
	}()

	go func() {
		//for {
		time.Sleep(1000)
		ch2 <- 2
		close(ch2)
		//}
	}()

	for {
		select {
		case x, ok := <-ch1:
			if ok {
				fmt.Println(x)
			} else {
				ch1 = nil
			}
		case x, ok := <-ch2:
			if ok {
				fmt.Println(x)
			} else {
				ch2 = nil
			}
		default:
			fmt.Println("default")
			time.Sleep(2000)
		}
	}
}
