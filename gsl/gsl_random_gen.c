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
 * @file gsl_random_gen.c
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Mon Jun 10 11:45:22 2013
 *
 **/

#include <stdio.h>
#include <gsl/gsl_rng.h>

int main (void) {
    const gsl_rng_type * T;
    gsl_rng * r;

    int i, n = 10;

    gsl_rng_env_setup();

    T = gsl_rng_default;
    r = gsl_rng_alloc (T);

    for (i = 0; i < n; i++) {
        double u = gsl_rng_uniform (r);
        printf ("%.5f\n", u);
    }

    gsl_rng_free (r);

    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
