all: main.cpp linked_list.cpp unit_tests.cpp
	g++ unit_tests.cpp linked_list.cpp -o unit_tests
	./unit_tests
	g++ main.cpp linked_list.cpp -o main

clean:
	rm main unit_tests
