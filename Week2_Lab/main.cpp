#include <iostream>
#include "functions.h"

int main(void) {
    using namespace std;

    cout << "n: (# of well-balanced) / (# total) " << endl;
    for (int n = 1; n < 20; n++) {
        double result = run_tests(n, 50000);
        cout << n << ": " << result << endl;
    }

    return 0;
}
