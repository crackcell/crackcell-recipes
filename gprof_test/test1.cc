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
 * @file test1.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Wed Oct 30 06:54:36 2013
 *
 **/

#include <iostream>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

void test2(vector<string> const& vec) {
  for (vector<string>::const_iterator it = vec.begin();
       it != vec.end(); it++) {
    if (it->compare("crackcell")) {
      cout << "found" << endl;
    } else {
      cout << "not found: " << *it << endl;
    }
  }
}

void test1(const int n) {
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    string tmp;
    try {
      tmp = lexical_cast<string>(i);
    } catch (...) {
      tmp = "-1";
    }
    vec.push_back(tmp);
  }
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < 100; i++) {
    test1(1000);
  }
  return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
