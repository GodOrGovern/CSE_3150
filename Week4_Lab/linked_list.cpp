#include <iostream>
#include "linked_list.h"

Node* build_linked_list(int elements) {
    if (elements < 1) {
        return nullptr;
    }

    Node* head = new Node;
    Node* node = head;
    for (int i = 0; i < elements-1; i++) {
        node->next = new Node;
        node->number = i;
        node = node->next;
    }
    node->number = elements-1;
    node->next = node;

    Node* last_node = node;
    node = head;
    for (int i = 0; i < elements; i++) {
        node->jumper = last_node;
        node = node->next;
    }

    return head;
}

void print_linked_list(Node* list, int elements) {
    Node* node = list;
    for (int i = 0; i < elements; i++) {
        std::cout << node->number << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int delete_linked_list(Node* list, int elements) {
    Node* node = list;
    Node* next_node;
    for (int i = 0; i < elements; i++) {
        next_node = node->next;
        delete node;
        node = next_node;
    }

    return 0;
}

int sum_values_in_linked_list(Node* list, int elements) {
    Node* node = list;
    int sum = 0;
    for (int i = 0; i < elements; i++) {
        sum += node->number;
        node = node->next;
    }

    return sum;
}
