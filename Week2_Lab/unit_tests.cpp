#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <algorithm>
#include "doctest.h"
#include "functions.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

int array1[10];
int test1[] = {1,-1};
int test2[] = {1,1,-1,-1};
int test3[] = {1,1,1,1,1,-1,-1,-1,-1,-1};

TEST_CASE("Test week 2 lab functions") {
  SUBCASE("fill_array") {
      fill_array(array1, 2);
      CHECK(std::equal(array1, array1+2, test1));
      fill_array(array1, 4);
      CHECK(std::equal(array1, array1+4, test2));
      fill_array(array1, 10);
      CHECK(std::equal(array1, array1+10, test3));
  };
  SUBCASE("check_array") {
  };
}
