#include <iostream>
#include "student_functions.h"

using namespace std;

double compute_hw_avg(const student& s) {
    double h_scores = 0.0;

    for (auto h_score : s.hw_grades) {
        h_scores += h_score;
    }

    return h_scores / s.hw_grades.size();
}

student get_student_struct() {
    student s;
    cout << "Enter the student's ID: ";
    cin >> s.id;

    cout << "Enter the student's name: ";
    cin >> s.name;

    cout << "Enter the student's midterm: ";
    cin >> s.midterm;

    cout << "Enter the student's final: ";
    cin >> s.final;

    cout << "Enter the student's homework (press CTRL-D when done): ";

    int score;
    while (cin >> score) {
        s.hw_grades.push_back(score);
    }

    s.hw_avg = compute_hw_avg(s);

    return s;
}

void output_student_struct_data(const student& s, const double& final_total_score) {
    cout << s.name << " (ID " << s.id << ") "
         << "earned a " << s.final << " on their final, "
         << "a " << s.midterm << " on their midterm, "
         << "and a " << s.hw_avg << " on their homework." << endl;

    cout << "Final total class score: " << final_total_score << endl;
}

double compute_class_score(const student& s) {
    return 0.3*s.midterm + 0.3*s.final + 0.4*s.hw_avg;
}
