#include <algorithm>
#include <iostream>
#include "functions.h"

int ECRemoveSpace(int nums[], int len, int val) {
    int i = 0;
    int end = len;
    while (i < end) {
        if (nums[i] == val) {
            std::swap(nums[i], nums[end-1]);
            end -= 1;
        } else {
            i += 1;
        }
    }

    return i;
}
