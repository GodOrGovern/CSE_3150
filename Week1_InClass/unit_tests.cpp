#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <algorithm>
#include <iostream>
#include "doctest.h"
#include "functions.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

void run_test(int nums[], int len, int test[], int val, int i) {
    int result = ECRemoveSpace(nums, len, val);
    CHECK(result == i);
    std::sort(nums, nums+result);
    std::sort(test, test+result);
    CHECK(std::equal(nums, nums+result, test));
}

int nums1[] = {1};
int test1_1[] = {};
int test1_2[] = {1};

int nums2[] = {1,2,3,4};
int test2_1[] = {1,3,4};
int test2_2[] = {1,2,3,4};

int nums3[] = {1,2,3,2,4,2};
int test3[] = {1,3,4};

int nums4[] = {7,7,7,1};
int test4_1[] = {1};
int test4_2[] = {7,7,7};

int nums5[] = {1,1,1,1};
int test5[] = {};

int nums6[] = {0,1,2,2,3,0,4,2};
int test6[] = {0,1,3,0,4};

TEST_CASE("Test week 1 in class") {
  SUBCASE("Test ECRemoveSpace") {
      run_test(nums1, ARRAY_SIZE(nums1), test1_1, 1, ARRAY_SIZE(test1_1));
      run_test(nums1, ARRAY_SIZE(nums1), test1_2, 2, ARRAY_SIZE(test1_2));

      run_test(nums2, ARRAY_SIZE(nums2), test2_1, 2, ARRAY_SIZE(test2_1));
      run_test(nums2, ARRAY_SIZE(nums2), test2_2, 5, ARRAY_SIZE(test2_2));

      run_test(nums3, ARRAY_SIZE(nums3), test3, 2, ARRAY_SIZE(test3));

      run_test(nums4, ARRAY_SIZE(nums4), test4_1, 7, ARRAY_SIZE(test4_1));
      run_test(nums4, ARRAY_SIZE(nums4), test4_2, 1, ARRAY_SIZE(test4_2));

      run_test(nums5, ARRAY_SIZE(nums5), test5, 1, ARRAY_SIZE(test5));

      run_test(nums6, ARRAY_SIZE(nums6), test6, 2, ARRAY_SIZE(test6));
  };
}
