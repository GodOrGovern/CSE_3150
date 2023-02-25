#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "doctest.h"
#include "student_functions.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

TEST_CASE("Test week 5 assignment") {
  SUBCASE("compute_class_score") {
      student s;
      s.final = 100;
      s.midterm = 80;
      s.hw_avg = 45;
      CHECK(compute_class_score(s) == 0.3*s.final + 0.3*s.midterm + 0.4*s.hw_avg);

      s.final = 0;
      s.midterm = 0;
      s.hw_avg = 0;
      CHECK(compute_class_score(s) == 0.3*s.final + 0.3*s.midterm + 0.4*s.hw_avg);

      s.final = 100;
      s.midterm = 100;
      s.hw_avg = 100;
      CHECK(compute_class_score(s) == 0.3*s.final + 0.3*s.midterm + 0.4*s.hw_avg);

      s.final = 60;
      s.midterm = 80;
      s.hw_avg = 90;
      CHECK(compute_class_score(s) == 0.3*s.final + 0.3*s.midterm + 0.4*s.hw_avg);
  };
}
