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

TEST_CASE("Test week 2 lab functions") {
  SUBCASE("fill_array") {
      fill_array(array1, 2);
      CHECK(std::equal(array1, array1+ARRAY_SIZE(test1), test1));
      fill_array(array1, 4);
      CHECK(std::equal(array1, array1+ARRAY_SIZE(test2), test2));
      fill_array(array1, 10);
      CHECK(std::equal(array1, array1+ARRAY_SIZE(test3), test3));
  };
  SUBCASE("check_array") {
      CHECK(check_array(test1, ARRAY_SIZE(test1)) == true);
      CHECK(check_array(test2, ARRAY_SIZE(test2)) == true);
      CHECK(check_array(test4, ARRAY_SIZE(test4)) == true);
      CHECK(check_array(test5, ARRAY_SIZE(test5)) == false);
      CHECK(check_array(test6, ARRAY_SIZE(test6)) == true);
      CHECK(check_array(test7, ARRAY_SIZE(test7)) == true);
      CHECK(check_array(test8, ARRAY_SIZE(test8)) == false);
  };
  SUBCASE("fisher_yates") {

  };
}
