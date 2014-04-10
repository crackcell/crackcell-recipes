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
#include <google/profiler.h>
#include <google/heap-profiler.h>

using namespace std;
using namespace boost;

int test3(const int n) {
  string tmp = "xxx";
  for (int i = 0; i < n; i++) {
    string a = tmp + "yyy";
  }
  return tmp.size();
}

void test2(vector<string> const& vec) {
  int z = test3(2);
  for (vector<string>::const_iterator it = vec.begin();
       it != vec.end(); it++) {
    if (it->compare("1")) {
      cout << "found" << endl;
    } else {
      cout << "not found: " << *it << z << endl;
    }
  }
}

void test1(const int n) {
  int z = test3(3);
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    string tmp2;
    try {
      tmp2 = lexical_cast<string>(i);
    } catch (...) {
      tmp2 = "xxx";
      cout << z << endl;
    }
    vec.push_back(tmp2);
  }
}

int main(int argc, char *argv[]) {
  ProfilerStart("CPUProfile");
  HeapProfilerStart("HeapProfile-test1");
  for (int i = 0; i < 100; i++) {
    test1(1000);
  }
  HeapProfilerDump(GetHeapProfile());
  HeapProfilerStop();
  ProfilerStop();
  return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
