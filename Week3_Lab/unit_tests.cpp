#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <algorithm>
#include "doctest.h"
#include "functions.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

int test1[] = {1,-1};
int test2[] = {1,-1,-1,-1,1,1};
int test3[] = {-1,1,1,1,-1,-1};
int test4[] = {-1,-1,1,1,1,-1};
int test5[] = {1,1,1,-1,-1,-1};

int array1[] = {-1,-1,-1,1,1,1,-1,1};
int shift1[] = {1,1,1,-1,1,-1,-1};

int array2[] = {-1,-1,-1,-1,1,1,1,1};
int shift2[] = {1,1,1,1,-1,-1,-1};

int array3[] = {-1,1,1,-1,-1,1,1,-1};
int shift3[] = {1,1,-1,-1,1,1,-1};

TEST_CASE("Test week 3 lab functions") {
  SUBCASE("Test lowest_prefix_sum") {
      CHECK(lowest_prefix_sum(test1, ARRAY_SIZE(test1)) == 1);
      CHECK(lowest_prefix_sum(test2, ARRAY_SIZE(test2)) == 3);
      CHECK(lowest_prefix_sum(test3, ARRAY_SIZE(test3)) == 0);
      CHECK(lowest_prefix_sum(test4, ARRAY_SIZE(test4)) == 1);
      CHECK(lowest_prefix_sum(test5, ARRAY_SIZE(test5)) == 5);
  };
  SUBCASE("Test shift_prefix") {
      int* new_array1 = shift_prefix(array1, ARRAY_SIZE(array1));
      CHECK(std::equal(shift1, shift1+ARRAY_SIZE(shift1), new_array1));
      delete[] new_array1;

      int* new_array2 = shift_prefix(array2, ARRAY_SIZE(array2));
      CHECK(std::equal(shift2, shift2+ARRAY_SIZE(shift2), new_array2));
      delete[] new_array2;

      int* new_array3 = shift_prefix(array3, ARRAY_SIZE(array3));
      CHECK(std::equal(shift3, shift3+ARRAY_SIZE(shift3), new_array3));
      delete[] new_array3;
  };
}
