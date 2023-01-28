#include <iostream>
#include "functions.h"

int main(void) {
    for (int n = 1; n < 20; n++) {
        double result = run_tests(n, 50000);
        std::cout << n << ": " << result << std::endl;
    }
    return 0;
}
