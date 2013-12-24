all : test1 test1_g

test1 :
	g++ -g -o test1 test1.cc -pg

test1_g :
	g++ -g -o test1_g test1_g.cc -lprofiler -ltcmalloc

clean :
	rm -rf *.o test1 test1_g

profile : all
	./test1
	gprof ./test1 > gprof.output

dot : profile
	gprof ./test1 | ./gprof2dot.py -s | dot -Tpng -o test1.png
