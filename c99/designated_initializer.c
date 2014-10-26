/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

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
 * @file designated_initializer.c
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Jul 27 15:51:01 2014
 *
 **/

#include <stdio.h>

typedef struct {
  const char * name;
  int age;
} person_t;

int main(int argc, char *argv[]) {
  person_t p = {.name="crackcell", .age=26};
  return 0;
}

/* vim: set expandtab shiftwidth=2 tabstop=2: */
