#include <vector>
#include <fstream>

#include "vector.h"

using namespace std;

int main() {
    ifstream in_file;
    in_file.open("vectors.txt");
    auto vectors = read_vectors(in_file);
    in_file.close();

    auto distances = get_distances(vectors);
    sort_vectors(distances);
    print_vectors(distances, vectors);

    return 0;
}

