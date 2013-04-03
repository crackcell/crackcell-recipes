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
 * @file edit_distance.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Tue Apr  2 14:52:54 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 1024

char m[MAX_LEN][MAX_LEN];

void print_m(const int len1, const int len2) {
    printf("matrix:\n");
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

static inline int min(const int a, const int b, const int c) {
    int tmp = a < b ? a : b;
    return tmp > c ? c : tmp;
}

int edit_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 0; i <= len1; i++) {
        m[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        m[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // 1. replace char: s1[i] to s2[j]
            // 2. delete char: s1[i]
            // 3. delete char: s2[i]
            m[i][j] = min(m[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1),
                          m[i - 1][j] + 1,
                          m[i][j - 1] + 1);
            //print_m(len1, len2);
        }
    }

    //print_m(len1, len2);
    return m[len1][len2];
}

int main(int argc, char *argv[]) {
    const char *s1 = "asgdfg124234";
    const char *s2 = "werfs1";
    printf("edit distance: %d\n", edit_distance(s1, s2));
    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
