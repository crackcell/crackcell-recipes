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
 * @file message1.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Jul 12 23:34:28 2013
 *
 **/

#include <stdio.h>
#include <mpi/mpi.h>

int main(int argc, char *argv[]) {
    int task_count;
    int rank;
    int dest;
    int src;
    int count;
    int tag = 1;

    char in_msg;

    char out_msg = 'x';

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &task_count);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (0 == rank) {
        dest = 1;
        src = 1;
        MPI_Send(&out_msg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
        MPI_Recv(&in_msg, 1, MPI_CHAR, src, tag, MPI_COMM_WORLD, &status);
    } else if (1 == rank) {
        dest = 0;
        src = 0;
        MPI_Recv(&in_msg, 1, MPI_CHAR, src, tag, MPI_COMM_WORLD, &status);
        MPI_Send(&out_msg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
    }

    MPI_Get_count(&status, MPI_CHAR, &count);
    printf("task %d: recv %d char(s) from task %d with tag %d\n",
           rank, count, status.MPI_SOURCE, status.MPI_TAG);

    MPI_Finalize();

    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
