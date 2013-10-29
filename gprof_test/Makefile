all : test1

test1 :
	g++ -ggdb -o test1 test1.cc -pg

clean :
	rm -rf *.o test1

profile : all
	./test1
	gprof ./test1 > gprof.output

dot : profile
	gprof ./test1 | gprof2dot > test1.dot
