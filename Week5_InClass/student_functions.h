#ifndef __STUDENT_FUNCTIONS_H_
#define __STUDENT_FUNCTIONS_H_

#include <vector>
#include <string>

using namespace std;

struct student {
    int id;
    string name;
    int final;
    int midterm;
    double hw_avg;
    vector<int> hw_grades;
};

student get_student_struct();
void output_student_struct_data(const student& s, const double& final_total_score);
double compute_class_score(const student& s);

#endif
