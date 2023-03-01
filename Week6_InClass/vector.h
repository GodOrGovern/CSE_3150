#ifndef __VECTOR_H_
#define __VECTOR_H_

#include <fstream>
#include <vector>

struct int_vector {
    int id;
    int from;
    int to;
    int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}; // copy constructor
    int_vector() : id(-1), from(0), to(0) {}; // basic constructor
};

std::vector<int_vector> read_vectors(std::ifstream& in_file);
void sort_vectors(std::vector<int_vector>& vect);
void print_vectors(const std::vector<int_vector>& vect);

#endif
