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

int partition(int *buf, int len, int p_pos) {
    swap(&buf[p_pos], &buf[len - 1]);
    int i_pos = 0;
    for (int i = 0; i < len - 1; i++) {
        if (buf[i] < buf[len - 1]) {
            swap(&buf[i_pos], &buf[i]);
            i_pos++;
        }
    }
    swap(&buf[len - 1], &buf[i_pos]);
    p_pos = i_pos;
    for (size_t i = 0; i < len; i++) {
        if (i == p_pos) {
            printf("[%d] ", buf[i]);
        } else {
            printf("%d ", buf[i]);
        }
    }
    printf("\n");
    return p_pos;
}

void qsort(int *buf, int len) {
    if (NULL == buf || len < 2) {
        return;
    }
    srandom(len);
    int p_pos = random() % len;
    p_pos = partition(buf, len, p_pos);
    qsort(buf, p_pos);
    qsort(buf + p_pos + 1, len - p_pos - 1);
}

int main(int argc, char *argv[]) {
    int buf[] = {1, 2, 6, 5, 3, 7, 1, 9, 8};
    size_t len = sizeof(buf) / sizeof(int);
    qsort(buf, sizeof(buf) / sizeof(int));
    for (size_t i = 0; i < len; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");
    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
