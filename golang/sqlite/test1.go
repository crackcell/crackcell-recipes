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
 * @file test1.go
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sat Nov 29 17:06:29 2014
 *
 **/

package main

import (
	_ "code.google.com/p/gosqlite/sqlite3"
	"database/sql"
	"fmt"
)

//===================================================================
// Public APIs
//===================================================================

//===================================================================
// Private
//===================================================================

func main() {
	db, err := sql.Open("sqlite3", "./data.sqlite3")
	if err != nil {
		panic(err)
	}
	defer db.Close()

	/*
		stmt1, err := db.Prepare(`create table test(name varchar(256), age int)`)
		if err != nil {
			panic(err)
		}
		defer stmt1.Close()
		stmt1.Exec()
	*/

	//stmt, err := db.Prepare(`insert into test(name,age) values(?,?)`)
	stmt, err := db.Prepare(`update test set age=? where name=?`)
	if err != nil {
		panic(err)
	}
	defer stmt.Close()

	if result, err := stmt.Exec(27, "crackcell"); err != nil {
		panic(err)
	} else {
		if id, err := result.LastInsertId(); err == nil {
			fmt.Println("insert id : ", id)
		}
	}
}
