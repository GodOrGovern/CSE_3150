#include <iostream>

#include "list.h"

using namespace std;

int main(void) {
    List l;

    l.push(1);
    l.push(2);
    l.push(3);

    cout << l.head->data << endl;
    cout << l.head->next->data << endl;
    cout << l.head->next->next->data << endl;
}
