#include <iostream>
#include "src/linked_list.h"

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);

    std::cout << "List after insertion:" << std::endl;
    list.display();

    list.deleteFromBeginning();
    std::cout << "List after deleting from beginning:" << std::endl;
    list.display();

    list.deleteFromEnd();
    std::cout << "List after deleting from end:" << std::endl;
    list.display();

    list.insertAtPosition(15, 2);
    std::cout << "List after inserting at position 2:" << std::endl;
    list.display();

    list.sort();
    std::cout << "List after sorting:" << std::endl;
    list.display();

    Node* middle = list.getMiddleNode();
    if (middle) {
        std::cout << "Middle node: " << middle->data << std::endl;
    }

    list.removeDuplicates();
    std::cout << "List after removing duplicates:" << std::endl;
    list.display();

    list.reverse();
    std::cout << "List after reversing:" << std::endl;
    list.display();

    return 0;
}
