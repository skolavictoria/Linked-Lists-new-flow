#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
public:
    int value;
    Node* next_member = nullptr;
    
    Node(int value) : value(value) {}
};

class LinkedList {
public:
    Node* head = nullptr;
    
    LinkedList() {}

    void push(int value) {
        Node* new_node = new Node(value);
        new_node->next_member = head;
        head = new_node;
    }
    
    void append(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next_member) temp = temp->next_member;
        temp->next_member = new_node;
    }
    
    void insert(int position, int value) {
        if (position == 0) {
            push(value);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp && i < position - 1; i++) temp = temp->next_member;
        if (!temp) return;
        Node* new_node = new Node(value);
        new_node->next_member = temp->next_member;
        temp->next_member = new_node;
    }
    
    int pop() {

    }
    
    void del(int position) {

    }
    
    Node* get_elem_by_index(int index) {
        Node* temp = head;
        for (int i = 0; temp && i < index; i++) temp = temp->next_member;
        return temp;
    }
    
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next_member;
            current->next_member = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    

    int get_len() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next_member;
        }
        return count;
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " -> ";
            temp = temp->next_member;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(5);
    list.push(3);
    list.append(7);
    list.insert(1, 4);
    list.display();
    list.reverse();
    list.display();
    //list.sort();
    list.display();
    //list.shuffle();
    list.display();
    //cout << "Found 4: " << list.search(4) << endl;
    cout << "Popped: " << list.pop() << endl;
    list.display();
    return 0;
}