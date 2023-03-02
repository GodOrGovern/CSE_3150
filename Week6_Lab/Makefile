all: unit_tests.cpp vector.cpp vector_main.cpp
	g++ unit_tests.cpp vector.cpp -o unit_tests
	./unit_tests
	g++ vector_main.cpp vector.cpp -o main

clean:
	rm main unit_tests
