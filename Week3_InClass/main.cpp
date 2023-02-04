#include <iostream>

#include "linked_list.h"

int main(void) {
    using namespace std;

    int elements = 10;
    cout << "Building list with " << elements << " elements" << endl;
    Node* list = build_linked_list(elements);

    int result = sum_values_in_linked_list(list, elements);
    cout << "Sum of values in list: " << result << endl;

    cout << "Printing list:" << endl;
    print_linked_list(list, elements);

    cout << "Deleting list" << endl;
    delete_linked_list(list, elements);

    return 0;
}
