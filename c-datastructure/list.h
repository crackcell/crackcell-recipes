/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _LIST_H_
#define _LIST_H_

/**
 * Linked list
 *
 * @file list.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Tue Sep 10 21:40:51 2013
 *
 **/

typedef struct ListElement_ {

    void                *data;
    struct ListElement_ *next;

} ListElement;

typedef struct List_ {

    int         size;
    int         (*match)(const void *key1, const void *key2);
    void        (*destroy)(void *data);

    ListElement *head;
    ListElement *tail;

} List;

void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);

#endif /* _LIST_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
