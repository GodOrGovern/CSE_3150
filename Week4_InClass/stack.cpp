#include "stack.h"
#include <iostream>
#include <stack>
#include <fstream>

void pushToStack(Stack& stack, int val) {
    Value tempVal;
    tempVal.val = val;
    stack.stack.push(tempVal);
    stack.sum += val;

    if (stack.sum < 0) {
        throw std::runtime_error("Negative sum");
    }
}

void popFromStack(Stack& stack) {
    if (!stack.stack.empty()) {
        stack.sum -= stack.stack.top().val;
        stack.stack.pop();
    }
}

void readTextFileToStack(Stack& stack, const char* filename) {
    std::ifstream inputFile(filename);
    int val;
    try {
        while (inputFile >> val) {
            pushToStack(stack, val);
        }
    } catch (std::exception& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
}

