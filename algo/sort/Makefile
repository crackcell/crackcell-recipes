# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Sat Feb 16 00:24:51 2013
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

include ../Makefile.env

BUILD_TARGETS = qsort.exe mergesort.exe

INC = -I../include -I./

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ_DEBUG = $(patsubst %.cpp, %_d.o, $(SRC))

.PHONY : all clean

all : $(BUILD_TARGETS)

%.exe : $(OBJ)
	$(CC) $(patsubst %.exe, %.o, $@) -o $@

clean :
	rm -rf $(OBJ) $(OBJ_DEBUG) $(BUILD_TARGETS)
