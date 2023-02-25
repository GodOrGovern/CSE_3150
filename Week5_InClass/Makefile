all: unit_tests.cpp student_functions.cpp student_main.cpp
	g++ unit_tests.cpp student_functions.cpp -o unit_tests
	./unit_tests
	g++ student_main.cpp student_functions.cpp -o main

clean:
	rm main unit_tests
