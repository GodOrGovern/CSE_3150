#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "doctest.h"
#include "vector.h"

using namespace std;

vector<double> v1 = {1.1, 2.2, 3.3};
vector<double> v2 = {1.5, 2.5, 3.5};
vector<double> v3 = {-0.2, -40, -10.5};
vector<vector<double>> vectors = {v1, v2, v3};
vector<pair<pair<int, int>, double>> distances;

TEST_CASE("Test week 6 lab") {
  SUBCASE("Test get_cos_distance") {
      CHECK(get_cos_distance(v1, v2) == doctest::Approx(0.07191));
      CHECK(get_cos_distance(v1, v3) == doctest::Approx(2.37728));
      CHECK(get_cos_distance(v2, v3) == doctest::Approx(2.38547));
  };
  SUBCASE("Test get_distances") {
      distances = get_distances(vectors);
      CHECK(distances[0].first == pair(0, 1));
      CHECK(distances[0].second == doctest::Approx(0.07191));
      CHECK(distances[1].first == pair(0, 2));
      CHECK(distances[1].second == doctest::Approx(2.37728));
      CHECK(distances[2].first == pair(1, 2));
      CHECK(distances[2].second == doctest::Approx(2.38547));
  };
  SUBCASE("Test sort_vectors") {
      sort_vectors(distances);
      CHECK(distances[0].first == pair(0, 1));
      CHECK(distances[1].first == pair(0, 2));
      CHECK(distances[2].first == pair(1, 2));
  };
  SUBCASE("Test file input") {
      // test empty file
      ifstream infile1("temp.txt");
      auto vectors1 = read_vectors(infile1);
      CHECK(vectors1.size() == 0);
      infile1.close();

      // check non-empty file
      ofstream outfile2("temp.txt");
      outfile2 << "1.1 2.2 3.3\n1.5 2.5 3.5";
      outfile2.close();
      ifstream infile2("temp.txt");
      auto vectors2 = read_vectors(infile2);
      CHECK(vectors2[0] == v1);
      CHECK(vectors2[1] == v2);
      infile2.close();
      remove("temp.txt");
  };
}
