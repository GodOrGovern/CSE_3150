#include <iostream>
#include <string>
#include <vector>
#include "student_functions.h"

using namespace std;

int main() {
    student s = get_student_struct();
    double class_score = compute_class_score(s);
    output_student_struct_data(s, class_score);

    return 0;
}
