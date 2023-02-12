#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "prefix_sum.h"

void fill_array(int array[], int length);
bool check_array(int array[], int length);
void fisher_yates(int array[], int length);
int lowest_prefix_sum(int array[], int length);
int* shift_prefix(int array[], int length);

#endif
