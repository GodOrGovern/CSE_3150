#include "prefix_sum.h"

int prefix_sum(int array[], int last) {
    int sum = 0;
    for (int i = 0; i < last; i++) {
        sum += array[i];
    }

    return sum;
}


bool non_negative_sum(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
        if (sum < 0) {
            return false;
        }
    }

    return true;
}

bool non_positive_sum(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
        if (sum > 0) {
            return false;
        }
    }

    return true;
}
