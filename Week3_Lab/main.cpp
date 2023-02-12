#include <iostream>
#include "functions.h"

void print_array(int array[], int length) {
    using namespace std;
    for (int i = 0; i < length; i++) {
        if (array[i] == 1) {
            cout << '(';
        } else {
            cout << ')';
        }
    }
    cout << endl;
}

int main(void) {
    using namespace std;

    int length = 20;
    int array[length];
    fill_array(array, length);

    for (int i = 0; i < 100; i++) {
        fisher_yates(array, length);
        int* new_array = shift_prefix(array, length);
        if (new_array[0] == -1) {
            continue;
        } else {
            print_array(new_array, length-1);
        }

        delete[] new_array;
    }

    return 0;
}
