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
 * @file hello3.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Jul 12 22:47:19 2013
 *
 **/

#include <stdio.h>
#include <mpi/mpi.h>

int main(int argc, char *argv[]) {
    char hostname[MPI_MAX_PROCESSOR_NAME];
    int task_count;
    int rank;
    int len;
    int ret;

    ret = MPI_Init(&argc, &argv);
    if (MPI_SUCCESS != ret) {
        printf("start mpi fail\n");
        MPI_Abort(MPI_COMM_WORLD, ret);
    }

    MPI_Comm_size(MPI_COMM_WORLD, &task_count);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(hostname, &len);

    printf("task_count = %d, my rank = %d on %s\n", task_count, rank, hostname);

    MPI_Finalize();

    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
