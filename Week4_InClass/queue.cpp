#include "queue.h"
#include <iostream>
#include <queue>
#include <fstream>

void pushToQueue(std::queue<int>& queue, int val) {
    queue.push(val);
}

void popFromQueue(std::queue<int>& queue) {
    if (!queue.empty()) {
        queue.pop();
    }
}

void readTextFileToQueue(std::queue<int>& queue, const char* filename) {
    std::ifstream inputFile(filename);
    int val;
    while (inputFile >> val) {
        pushToQueue(queue, val);
    }
}

