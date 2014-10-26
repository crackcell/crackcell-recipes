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
 * @file compound_literals.c
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Jul 27 10:53:20 2014
 *
 **/

#include <stdio.h>
#include <math.h> // NAN

void f(double array[]) {
  int i;
  for (i = 0; !isnan(array[i]); i++) {
    printf("%f\n", array[i]);
  }
}

int main(int argc, char *argv[]) {
  f((double[]){20.38, 9.8, NAN});
  return 0;
}

/* vim: set expandtab shiftwidth=2 tabstop=2: */
