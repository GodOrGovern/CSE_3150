#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "doctest.h"
#include "linked_list.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

Node* list1 = build_linked_list(0);
Node* list2 = build_linked_list(1);
Node* list3 = build_linked_list(3);

TEST_CASE("Test week 3 functions") {
  SUBCASE("Testing build_linked_list") {
      CHECK(list1 == nullptr);
      CHECK(list2->number == 0);
      CHECK(list2->next == list2);
      CHECK(list3->number == 0);
      CHECK(list3->next->number == 1);
      CHECK(list3->next->next->number == 2);
      CHECK(list3->next->next->next == list3->next->next);
  };
  SUBCASE("Testing print_linked_list") {
      std::stringstream buffer;
      std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

      print_linked_list(list1, 0);
      CHECK(buffer.str() == "\n");

      buffer.str("");
      print_linked_list(list2, 1);
      CHECK(buffer.str() == "0 \n");

      buffer.str("");
      print_linked_list(list3, 3);
      CHECK(buffer.str() == "0 1 2 \n");

      std::cout.rdbuf(old);
  };
  SUBCASE("Testing sum_values_in_linked_list") {
      CHECK(sum_values_in_linked_list(list1, 0) == 0);
      CHECK(sum_values_in_linked_list(list2, 1) == 0);
      CHECK(sum_values_in_linked_list(list3, 3) == 3);
  };
  SUBCASE("Testing delete_linked_list") {
      CHECK(delete_linked_list(list1, 0) == 0);
      CHECK(delete_linked_list(list2, 1) == 0);
      CHECK(delete_linked_list(list3, 3) == 0);
  };
}
