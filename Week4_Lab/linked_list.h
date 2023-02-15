#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

typedef struct node {
    int number;
    struct node* next;
    struct node* jumper;
} Node;

Node* build_linked_list(int elements);
void print_linked_list(Node* list, int elements);
int delete_linked_list(Node* list, int elements);
int sum_values_in_linked_list(Node* list, int elements);

#endif
