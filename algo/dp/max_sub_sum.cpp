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
 * @file max_sub_sum.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Apr  7 00:06:04 2013
 *
 **/

#include <stdio.h>

int max_sub_sum(int *a, int n) {
    if (NULL == a || n < 1) {
        return 0;
    }

    int max_sum = a[0];
    int sum = a[0] < 0 ? 0 : a[0];

    for (int i = 1; i < n; i++) {
        sum += a[i];
        if (sum > max_sum) {
            max_sum = sum;
        } else if (sum < 0) {
            sum = 0;
        }
    }

    return max_sum;
}

int main(int argc, char *argv[]) {
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int max = max_sub_sum(a, sizeof(a) / sizeof(int));
    printf("max=%d\n", max);
    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
