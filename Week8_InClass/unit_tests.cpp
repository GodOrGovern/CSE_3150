#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include <iostream>
#include <vector>
#include "doctest.h"
#include "graph.h"

using namespace std;

vector<int> v1 = {0, 1, 1};
vector<int> v2 = {1, 0, 0};

TEST_CASE("Test week 8 assignment") {
  SUBCASE("Test read_graph") {
      // test empty file
      ifstream infile1("temp.txt");
      auto graph1 = read_graph(infile1);
      CHECK(graph1.size() == 0);
      infile1.close();

      // check non-empty file
      ofstream outfile2("temp.txt");
      outfile2 << "0 1 1\n1 0 0\n1 0 0";
      outfile2.close();
      ifstream infile2("temp.txt");
      auto graph2 = read_graph(infile2);
      CHECK(graph2[0] == v1);
      CHECK(graph2[1] == v2);
      CHECK(graph2[2] == v2);
      infile2.close();
      remove("temp.txt");
  };
}
