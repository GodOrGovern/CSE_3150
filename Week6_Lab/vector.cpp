#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "vector.h"

using namespace std;

vector<vector<double>> read_vectors(ifstream& in_file) {
    vector<vector<double>> vectors;
    string line;

    while (getline(in_file, line)) {
        vector<double> vector;
        stringstream ss(line);
        double num;

        while (ss >> num) {
            vector.push_back(num);
        }

        vectors.push_back(vector);
    }

    return vectors;
}

double get_dot_product(const vector<double>& v1, const vector<double>& v2) {
    double product = 0.0;

    for (int i = 0; i < v1.size(); i++) {
        product += v1[i] * v2[i];
    }

    return product;
}

double get_magnitude(const vector<double>& vect) {
    double magnitude = 0.0;

    for (auto n : vect) {
        magnitude += n*n;
    }

    return sqrt(magnitude);
}

double get_cos_distance(const vector<double>& v1, const vector<double>& v2) {
    double dot_product = get_dot_product(v1, v2);
    double magnitude_v1 = get_magnitude(v1);
    double magnitude_v2 = get_magnitude(v2);
    return acos(dot_product / (magnitude_v1 * magnitude_v2));
}

vector<pair<pair<int, int>, double>> get_distances(const vector<vector<double>>& vectors) {

    vector<pair<pair<int, int>, double>> distances;

    for (int i = 0; i < vectors.size(); i++) {
        for (int j = i + 1; j < vectors.size(); j++) {
            double distance = get_cos_distance(vectors[i], vectors[j]);
            distances.push_back(make_pair(make_pair(i, j), distance));
        }
    }

    return distances;
}

void sort_vectors(vector<pair<pair<int, int>, double>>& distances) {
    sort(distances.begin(), distances.end(),
        [](const auto& v1, const auto& v2) {
            return v1.second < v2.second;
        });
}

void print_vector(const vector<double>& vect) {
    cout << "(";
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i];
        if (i != vect.size() - 1) {
            cout << ",";
        }
    }
    cout << ")";
}

void print_vectors(const vector<pair<pair<int, int>, double>>& distances,
                   const vector<vector<double>>& vectors) {
    for (const auto& pair : distances) {
        print_vector(vectors[pair.first.first]);
        cout << ", ";
        print_vector(vectors[pair.first.second]);
        cout << ": distance " << pair.second << endl;
    }
}
