#include <cstdlib>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>

#include "functions.h"
#include "prefix_sum.h"

void fill_array(int array[], int length) {
    for (int i = 0; i < length/2; i++) {
        array[i] = 1;
    }
    for (int i = length/2; i < length; i++) {
        array[i] = -1;
    }
}

bool check_array(int array[], int length) {
    return non_negative_sum(array, length) || non_positive_sum(array, length);
}

void fisher_yates(int array[], int length) {
    std::random_device random;
    std::srand(random());
    for (int i = length-1; i > 0; i--) {
        int j = std::rand() % (i + 1);
        std::swap(array[i], array[j]);
    }
}

double run_tests(int n, int tests) {
    int length = 2*n;
    int array[length];
    fill_array(array, length);

    double balanced = 0;
    for (int i = 0; i < tests; i++) {
        fisher_yates(array, length);
        balanced += check_array(array, length);
    }

    return balanced / (double)tests;
}
