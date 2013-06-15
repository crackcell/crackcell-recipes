/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 * 
 *
 * @file type_traits_test.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Tue Jul  2 21:38:56 2013
 *
 **/

#include <stdio.h>
#include <tr1/type_traits>

template<typename T>
void print_if_fundamental(const T v, std::tr1::true_type) {
    printf("true\n");
}

template<typename T>
void print_if_fundamental(const T v, std::tr1::false_type) {
    printf("false\n");
}

template<typename T>
void print_if_const(const T v, std::tr1::true_type) {
    printf("const\n");
}

template<typename T>
void print_if_const(const T v, std::tr1::false_type) {
    printf("not const\n");
}

template<typename T>
void print(T &v) {
    print_if_fundamental(v, std::tr1::is_fundamental<T>());
}

template<typename T>
void print_if_const(T &v) {
    print_if_const(v, std::tr1::is_const<T>());
    print_if_const(v, std::tr1::is_const<typename std::tr1::add_const<T>::type>());
}

int main(int argc, char *argv[]) {
    int v = 1;
    int *pv = &v;
    print(v);
    print(pv);
    print_if_const(v);
    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
