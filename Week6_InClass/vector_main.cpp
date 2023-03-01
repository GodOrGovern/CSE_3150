#include <vector>
#include <fstream>

#include "vector.h"

using namespace std;

int main() {
    ifstream in_file;
    in_file.open("vectors.txt");

    vector<int_vector> vect = read_vectors(in_file);
    sort_vectors(vect);
    print_vectors(vect);

    in_file.close();
    return 0;
}
