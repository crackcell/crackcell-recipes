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
 * @file submatch.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Nov 28 15:21:19 2014
 *
 **/

package main

import (
	"fmt"
	"regexp"
)

//===================================================================
// Public APIs
//===================================================================

//===================================================================
// Private
//===================================================================

func main() {
	varPattern := regexp.MustCompile(`\$\(([a-zA-Z0-9_]+)\)`)
	for _, g := range varPattern.FindAllSubmatch([]byte("sdfsdf $(biz_date), $(date)"), -1) {
		fmt.Println(string(g[1]))
	}
}
