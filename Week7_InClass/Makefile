all: perfect.cpp main.cpp unit_tests.cpp
	g++ unit_tests.cpp perfect.cpp -o unit_tests
	./unit_tests
	g++ main.cpp perfect.cpp -o main

clean:
	rm unit_tests main
