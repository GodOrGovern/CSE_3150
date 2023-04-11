#ifndef __MATRIX_H
#define __MATRIX_H

#include <iostream>
#include <utility>
#include <random>

#include "bigint.h"

using Fraction = std::pair<bigint, bigint>;

struct Matrix {
    Fraction** matrix;
    int rows;
    int cols;

    Matrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new Fraction*[r];
        for (int i = 0; i < r; i++) {
            matrix[i] = new Fraction[c];
        }
    }

    ~Matrix() {
        for (int row = 0; row < rows; row++) {
            delete[] matrix[row];
        }
        delete[] matrix;
    };
};

bigint gen_random() {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    static std::uniform_int_distribution<int> uni(0, 10);
    return bigint(uni(rng));
}

Fraction gen_fraction() {
    bigint numer = gen_random();
    bigint denom = gen_random();
    while (denom == bigint(0)) {
        denom = gen_random();
    }
    bigint gcd = big_gcd(numer, denom);
    return Fraction(numer / gcd, denom / gcd);
}

Matrix gen_matrix(const int& n, const int& m) {
    Matrix matrix(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix.matrix[i][j] = gen_fraction();
        }
    }

    return matrix;
}

void print_matrix(const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            std::cout << matrix.matrix[i][j].first << "/"
                      << matrix.matrix[i][j].second << " ";
        }
        std::cout << std::endl;
    }
}

Fraction mult_fractions(Fraction& a, Fraction& b) {
    return Fraction(a.first * b.first, a.second * b.second);
}

Fraction add_fractions(Fraction a, Fraction b) {
    bigint lcm = big_lcm(a.second, b.second);
    bigint numerator = (lcm / a.second) * a.first + (lcm / b.second) * b.first;
    bigint gcd = big_gcd(numerator, lcm);
    return Fraction(numerator / gcd, lcm / gcd);
}

Matrix mult_matrices(Matrix& mat1, Matrix& mat2) {
    if (mat1.cols != mat2.rows) {
        throw std::string("Not compatible");
    }

    Matrix result(mat1.rows, mat2.cols);
    for(int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.matrix[i][j] = Fraction(0, 1);
            for (int k = 0; k < mat1.cols; k++) {
                result.matrix[i][j] = add_fractions(result.matrix[i][j], mult_fractions(mat1.matrix[i][k], mat2.matrix[k][j]));
            }
        }
    }

    return result;
}

#endif
