#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <algorithm>
#include <iostream>
#include "doctest.h"
#include "stack.h"
#include "queue.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

int length = 7;
int array[7] = {1,2,3,4,5,6,-40};

TEST_CASE("Test week 4 in class") {
  SUBCASE("Test stack") {
      Stack stack;
      readTextFileToStack(stack, "file.txt");
      for (int i = length; i > 0; i--) {
          CHECK(stack.stack.top().val == array[i-1]);
          popFromStack(stack);
      }
  };
  SUBCASE("Test queue") {
      std::queue<int> queue;
      readTextFileToQueue(queue, "file.txt");
      for (int i = 0; i < length; i++) {
          CHECK(queue.front() == array[i]);
          popFromQueue(queue);
      }
  };
}
