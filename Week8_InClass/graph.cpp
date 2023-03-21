#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"

using namespace std;

vector<vector<int>> read_graph(ifstream& in_file) {
    vector<vector<int>> graph;
    string line;

    while (getline(in_file, line)) {
        vector<int> vector;
        stringstream ss(line);
        int num;

        while (ss >> num) {
            vector.push_back(num);
        }

        graph.push_back(vector);
    }

    return graph;
}

