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
 * @file qsort.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Tue Apr  2 09:34:26 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(int *buf, int len, int mid) {
    int *tmp = (int*)malloc(sizeof(int) * len);
    if (NULL == tmp) {
        exit(-1);
    }
    int i = 0;
    int j = mid;
    int i_pos = 0;
    while (i < mid || j < len) {
        if ((i <= mid - 1) && (j <= len - 1)) {
            if (buf[i] < buf[j]) {
                tmp[i_pos] = buf[i];
                i++;
                i_pos++;
            } else {
                tmp[i_pos] = buf[j];
                j++;
                i_pos++;
            }
        } else if (i <= mid - 1) {
            for (; i < mid; i++) {
                tmp[i_pos] = buf[i];
                i_pos++;
            }
        } else if (j <= len - 1) {
            for (; j < len; j++) {
                tmp[i_pos] = buf[j];
                i_pos++;
            }
        }
    }

    for (i = 0; i < len; i++) {
        buf[i] = tmp[i];
    }

    free(tmp);

    printf("merge: ");
    for (size_t i = 0; i < len; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");
}

void mergesort(int *buf, int len) {
    if (NULL == buf || len <= 1) {
        return;
    }

    printf("mergesort: ");
    for (size_t i = 0; i < len; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");

    int mid = len / 2;
    mergesort(buf, mid);
    mergesort(buf + mid, len - mid);

    merge(buf, len, mid);
}

int main(int argc, char *argv[]) {
    int buf[] = {1, 2, 6, 5, 3, 7, 1, 9, 8};
    //int buf[] = {3, 1, 2, 7, 4};
    //int buf[] = {2, 7, 4};
    size_t len = sizeof(buf) / sizeof(int);
    mergesort(buf, sizeof(buf) / sizeof(int));
    for (size_t i = 0; i < len; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");
    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
