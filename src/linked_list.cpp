#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList() {
    clear();
}
void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}
void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void LinkedList::insertAtPosition(int value, int position) {
    if (position <= 0 || position > size + 1) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
    } else {
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

bool LinkedList::deleteFromBeginning() {
    if (isEmpty()) {
        return false;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
    return true;
}

bool LinkedList::deleteFromEnd() {
    if (isEmpty()) {
        return false;
    }
    if (head->next == nullptr) {  
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    size--;
    return true;
}

bool LinkedList::deleteFromPosition(int position) {
    if (position <= 0 || position > size) {
        return false;
    }
    if (position == 1) {
        return deleteFromBeginning();
    } else {
        Node* temp = head;
        for (int i = 1; i < position - 1; ++i) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        size--;
        return true;
    }
}

bool LinkedList::deleteValue(int value) {
    if (isEmpty()) {
        return false;
    }
    if (head->data == value) {
        return deleteFromBeginning();
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        return false;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    size--;
    return true;
}

int LinkedList::getSize() const {
    return size;
}
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::display() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* LinkedList::search(int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void LinkedList::sort() {
    if (isEmpty() || head->next == nullptr) {
        return;
    }
    bool swapped;
    do {
        swapped = false;
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->data > temp->next->data) {
                std::swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void LinkedList::removeDuplicates() {
    Node* current = head;
    while (current && current->next) {
        Node* temp = current;
        while (temp->next) {
            if (current->data == temp->next->data) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
                size--;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

Node* LinkedList::getMiddleNode() {
    if (isEmpty()) {
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool LinkedList::detectLoop() const {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
void LinkedList::clear() {
    while (head) {
        deleteFromBeginning();
    }
}
