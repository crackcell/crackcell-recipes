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

BUILD_TARGETS = qsort mergesort

INC = -I../include -I./ -I$(SCWS)/include

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ_DEBUG = $(patsubst %.cpp, %_d.o, $(SRC))

.PHONY : all clean

all : $(BUILD_TARGETS)

qsort : $(OBJ)
	$(CC) qsort.o -o qsort

mergesort : $(OBJ)
	$(CC) mergesort.o -o mergesort

clean :
	rm -rf $(OBJ) $(OBJ_DEBUG) $(BUILD_TARGETS)
