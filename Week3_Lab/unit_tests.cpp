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
int test4[] = {1,-1,1,-1};
int test5[] = {1,-1,1,-1,-1};
int test6[] = {1};
int test7[] = {-1};
int test8[] = {-1,-1,1,1,1,-1};

TEST_CASE("Test week 3 lab functions") {
  SUBCASE("Test lowest_prefix_sum") {
  };
  SUBCASE("Test shift_prefix") {
  };
}
