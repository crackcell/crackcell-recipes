# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Mon Jun 10 08:02:16 2013
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

VERSION = 1.0.0.0

OS = $(shell uname)
CPU = $(shell uname -m)

CC = mpicxx
CFLAGS = -g -Wall -D_REENTRANT -D_GNU_SOURCE -D$(OS) -D$(CPU) -D__VERSION_ID__="\"$(VERSION)\"" -Wformat -Wall -Werror
CFLAGS_DEBUG = -g -Wall -D_REENTRANT -D_GNU_SOURCE -D$(OS) -D$(CPU) -D__VERSION_ID__="\"$(VERSION)_DEBUG\"" -D_DEBUG
CFLAGS_TEST = -g -Wall -D_REENTRANT -D_GNU_SOURCE -D$(OS) -D$(CPU) -D__VERSION_ID__="\"$(VERSION)_TEST\"" -D_DEBUG
MAKE = make

LINK = mpicxx
LINKFLAGS = -rdynamic

LIB =

%.o : %.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

INC = -I../include -I./

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
BIN = $(patsubst %.cpp, %.exe, $(SRC))

.PHONY : all clean

all : $(BIN)

%.exe : %.cpp
	$(CC) -o $@ $^ $(LIB)

clean :
	rm -rf $(OBJ) $(BIN)


