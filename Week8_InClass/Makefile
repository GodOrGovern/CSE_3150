all: graph.cpp main.cpp unit_tests.cpp
	g++ unit_tests.cpp graph.cpp -o unit_tests
	./unit_tests
	g++ main.cpp graph.cpp -o main

clean:
	rm unit_tests main
