all: prefix_sum.o unit_tests_prefix_sum.o
	g++ prefix_sum.o unit_tests_prefix_sum.o -o unit_tests
	./unit_tests

prefix_sum.o: prefix_sum.cpp
	g++ -c prefix_sum.cpp

unit_tests_prefix_sum.o: unit_tests_prefix_sum.cpp prefix_sum.o
	g++ -c unit_tests_prefix_sum.cpp

clean:
	rm -f unit_tests prefix_sum.o unit_tests_prefix_sum.o
