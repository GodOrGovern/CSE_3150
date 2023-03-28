#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <iostream>
#include "doctest.h"
#include "list.h"

using namespace std;

TEST_CASE("Test week 9 assignment") {
  SUBCASE("Test List") {
    List l;

    // Check empty list
    CHECK(l.head == nullptr);

    l.push(1);
    l.push(2);
    l.push(3);

    CHECK(l.head->data == 3);
    CHECK(l.head->next->data == 2);
    CHECK(l.head->next->next->data == 1);
  };
}
