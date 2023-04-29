#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <iostream>
#include <algorithm>

#include "doctest.h"
#include "matrix.h"

using namespace std;

TEST_CASE("Test week 11 assignment") {
  SUBCASE("mult_matrices") {
      Matrix m1(2, 2);
      Fraction temp1[2][2] = {{Fraction(1, 2), Fraction(3, 4)}, {Fraction(7, 3), Fraction(10, 3)}};
      for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              m1.matrix[i][j] = temp1[i][j];
          }
      }

      Matrix m2(2, 2);
      Fraction temp2[2][2] = {{Fraction(1, 2), Fraction(3, 4)}, {Fraction(7, 3), Fraction(10, 3)}};
      for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              m2.matrix[i][j] = temp2[i][j];
          }
      }

      Matrix m3 = mult_matrices(m1, m2);
      Fraction temp3[2][2] = {{Fraction(2, 1), Fraction(23, 8)}, {Fraction(161, 18), Fraction(463, 36)}};

      for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              CHECK(m3.matrix[i][j].first == temp3[i][j].first);
              CHECK(m3.matrix[i][j].second == temp3[i][j].second);
          }
      }
  }
}
