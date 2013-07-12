/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _LOGREG_H_
#define _LOGREG_H_

/**
 * 
 *
 * @file logreg.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Jul 12 17:22:28 2013
 *
 **/

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#ifdef __GNUC__
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif

static inline float sigmoid(gsl_vector *p, gsl_vector *out) {
    if (NULL == p || NULL == out) {
        return 1;
    }

    if (unlikely(p->size != out->size)) {
        return 1;
    }

    float value;
    for (int i = 0; i < p->size; i++) {
        //value = ;
        gsl_vector_set(out, i, 1 / exp(-gsl_vector_get(p, i)));
    }

    return 0;
}

#endif /* _LOGREG_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
