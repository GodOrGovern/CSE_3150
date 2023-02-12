#ifndef __STACK_H
#define __STACK_H

#include "value.h"
#include <iostream>
#include <stack>
#include <fstream>

typedef struct Stack {
    std::stack<Value> stack;
    int sum;
} Stack;

void pushToStack(Stack& stack, int val);
void popFromStack(Stack& stack);
void readTextFileToStack(Stack& stack, const char* filename);

#endif
