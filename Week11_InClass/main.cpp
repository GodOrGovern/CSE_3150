#include <iostream>

#include "matrix.h"

using namespace std;

int main(void) {
    cout << "First matrix: " << endl;
    Matrix mat1 = gen_matrix(4, 4);
    print_matrix(mat1);
    cout << endl;

    cout << "Second matrix: " << endl;
    Matrix mat2 = gen_matrix(4, 4);
    print_matrix(mat2);
    cout << endl;

    cout << "Product: " << endl;
    Matrix mat3 = mult_matrices(mat1, mat2);
    print_matrix(mat3);

    return 0;
}
