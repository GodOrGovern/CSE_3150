#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>
#include <queue>
#include <fstream>

void pushToQueue(std::queue<int>& queue, int val);
void popFromQueue(std::queue<int>& queue);
void readTextFileToQueue(std::queue<int>& queue, const char* filename);

#endif
