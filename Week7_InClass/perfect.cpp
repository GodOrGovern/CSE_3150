#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#include "perfect.h"

using namespace std;

bool is_perfect(int num) {
    int divisor_sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            divisor_sum += i;
        }
    }

    return divisor_sum == num;
};

void print_perfect_to(int n) {
    vector<int> vector(n);
    iota(vector.begin(), vector.end(), 1);
    for_each(vector.begin(), vector.end(),
             [](int num) {
                if (is_perfect(num)) {
                    cout << num << " is perfect" << endl;
                }
             });
};

