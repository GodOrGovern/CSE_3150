#include <cstdlib>
#include <random>
#include <algorithm>
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

int lowest_prefix_sum(int array[], int length) {
    if (length < 1) {
        return 0;
    }

    int low_index = 0;
    int low_sum = array[0];
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += array[i];
        if (sum < low_sum) {
            low_index = i;
            low_sum = sum;
        }
    }

    return low_index;
}

int* shift_prefix(int array[], int length) {
    int* new_array = new int[length-1];
    int low_index = lowest_prefix_sum(array, length);

    // number of elements after low_index
    int split = length-low_index-1;

    // copies elements from array[low_index+1..length] to new_array[0..split]
    for (int i = 0; i < split; i++) {
        new_array[i] = array[low_index+i+1];
    }
    // copies elements from array[0..low_index] to new_array[split..length-1]
    for (int i = split; i < length-1; i++) {
        new_array[i] = array[i-split];
    }

    return new_array;
}
