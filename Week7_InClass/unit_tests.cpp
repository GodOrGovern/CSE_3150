#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <iostream>
#include <vector>
#include "doctest.h"
#include "perfect.h"

using namespace std;

TEST_CASE("Test week 7 assignment") {
  SUBCASE("Test is_perfect") {
      for (int i = 1; i < 100; i++){
          if (i != 6 && i != 28) {
              CHECK(is_perfect(i) == false);
          } else {
              CHECK(is_perfect(i) == true);
          }
      }
  };
}
