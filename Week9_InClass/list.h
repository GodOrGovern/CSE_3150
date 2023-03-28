#ifndef __LIST_H_
#define __LIST_H_

#include <memory>

struct List
{
    struct Node {
        int data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;

    ~List() {
        while (head) {
            head = std::move(head->next);
        }
    }

    void push(int data) {
        head = std::unique_ptr<Node>(new Node{data, std::move(head)});
    }
};

#endif
