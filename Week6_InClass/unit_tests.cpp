#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */ #include <iostream>
#include <fstream>
#include <vector>
#include "doctest.h"
#include "vector.h"

using namespace std;

TEST_CASE("Test week 6 assignment") {
  SUBCASE("Test basic constructor") {
      int_vector vect;
      CHECK(vect.id == -1);
      CHECK(vect.from == 0);
      CHECK(vect.to == 0);
  };
  SUBCASE("Test copy constructor") {
      int_vector v1;
      v1.id = 1;
      v1.from = 2;
      v1.to = 3;
      int_vector v2(v1);
      CHECK(v2.id == 1);
      CHECK(v2.from == 2);
      CHECK(v2.to == 3);
  };
  SUBCASE("Test file input") {
      // test empty file
      ifstream infile1("temp.txt");
      vector<int_vector> vect1 = read_vectors(infile1);
      CHECK(vect1.size() == 0);
      infile1.close();

      // check non-empty file
      ofstream outfile2("temp.txt");
      outfile2 << "1 2\n3 4";
      outfile2.close();
      ifstream infile2("temp.txt");
      vector<int_vector> vect2 = read_vectors(infile2);
      CHECK(vect2[0].id == 0);
      CHECK(vect2[0].from == 1);
      CHECK(vect2[0].to == 2);
      CHECK(vect2[1].id == 1);
      CHECK(vect2[1].from == 3);
      CHECK(vect2[1].to == 4);
      infile2.close();
      remove("temp.txt");
  };
}
