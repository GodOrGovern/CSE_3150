#include <fstream>
#include <vector>
#include <iostream>
#include "graph.h"

using namespace std;

int main(void) {
    ifstream in_file;
    in_file.open("graph.txt");
    auto graph = read_graph(in_file);
    in_file.close();

    for (auto v : graph) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
