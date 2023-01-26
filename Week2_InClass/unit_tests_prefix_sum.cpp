#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "doctest.h"
#include "prefix_sum.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

int nums_0[] = {};
int nums_1[] = {-5};
int nums_2[] = {35};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};
int nums_6[] = {-1,-1,-1,-1,-1,6};
int nums_7[] = {0,0,0,0,0};
int nums_8[] = {1,-1,1,-1,1,-1};
int nums_9[] = {-1,1,-1,1,-1,1};

TEST_CASE("Test week1/2 functions") {
  SUBCASE("non-negative prefix sums") {
      CHECK(non_negative_sum(nums_0, ARRAY_SIZE(nums_0)) == true);
      CHECK(non_negative_sum(nums_1, ARRAY_SIZE(nums_1)) == false);
      CHECK(non_negative_sum(nums_2, ARRAY_SIZE(nums_2)) == true);
      CHECK(non_negative_sum(nums_3, ARRAY_SIZE(nums_3)) == false);
      CHECK(non_negative_sum(nums_4, ARRAY_SIZE(nums_4)) == true);
      CHECK(non_negative_sum(nums_5, ARRAY_SIZE(nums_5)) == false);
      CHECK(non_negative_sum(nums_6, ARRAY_SIZE(nums_6)) == false);
      CHECK(non_negative_sum(nums_7, ARRAY_SIZE(nums_7)) == true);
      CHECK(non_negative_sum(nums_8, ARRAY_SIZE(nums_8)) == true);
      CHECK(non_negative_sum(nums_9, ARRAY_SIZE(nums_9)) == false);
  };
  SUBCASE("non-positive prefix sums") {
      CHECK(non_positive_sum(nums_0, ARRAY_SIZE(nums_0)) == true);
      CHECK(non_positive_sum(nums_1, ARRAY_SIZE(nums_1)) == true);
      CHECK(non_positive_sum(nums_2, ARRAY_SIZE(nums_2)) == false);
      CHECK(non_positive_sum(nums_3, ARRAY_SIZE(nums_3)) == false);
      CHECK(non_positive_sum(nums_4, ARRAY_SIZE(nums_4)) == false);
      CHECK(non_positive_sum(nums_5, ARRAY_SIZE(nums_5)) == true);
      CHECK(non_positive_sum(nums_6, ARRAY_SIZE(nums_6)) == false);
      CHECK(non_positive_sum(nums_7, ARRAY_SIZE(nums_7)) == true);
      CHECK(non_positive_sum(nums_8, ARRAY_SIZE(nums_8)) == false);
      CHECK(non_positive_sum(nums_9, ARRAY_SIZE(nums_9)) == true);
  };
}
