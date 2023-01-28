#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "prefix_sum.h"

void fill_array(int array[], int length);
bool check_array(int array[], int length);
void fisher_yates(int array[], int length);
double run_tests(int n, int tests);

#endif
