# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Tue Apr  2 14:51:21 2013
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

all :
	make -C algo

clean :
	make clean -C algo
