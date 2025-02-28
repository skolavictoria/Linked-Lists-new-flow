#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;           
    Node* next;         
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;         
    int size;           

public:
    LinkedList();
    ~LinkedList();
    
    
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);
    bool deleteFromBeginning();
    bool deleteFromEnd();
    bool deleteFromPosition(int position);
    bool deleteValue(int value);
    int getSize() const;
    bool isEmpty() const;
    void display() const;

    Node* search(int value);
    void reverse();
    void sort();
    void removeDuplicates();
    Node* getMiddleNode();
    bool detectLoop() const;
    void clear();
};

#endif
