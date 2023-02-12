#include "stack.h"
#include "queue.h"
#include <iostream>

int main() {
    using namespace std;

    Stack stack;
    readTextFileToStack(stack, "file.txt");
    cout << stack.sum << endl;

    std::queue<int> queue;
    readTextFileToQueue(queue, "file.txt");
    cout << queue.front() << endl;
    return 0;
}
