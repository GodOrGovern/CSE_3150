#ifndef __VECTOR_H_
#define __VECTOR_H_

#include <fstream>
#include <vector>
#include <utility>

std::vector<std::vector<double>> read_vectors(std::ifstream& in_file);
double get_cos_distance(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<std::pair<std::pair<int, int>, double>> get_distances(const std::vector<std::vector<double>>& vectors);
void sort_vectors(std::vector<std::pair<std::pair<int, int>, double>>& distances);
void print_vectors(const std::vector<std::pair<std::pair<int, int>, double>>& distances,
                   const std::vector<std::vector<double>>& vectors);

#endif
