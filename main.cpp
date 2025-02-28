#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next_member;

    Node(int val) {
        value = val;
        next_member = nullptr;
    }
};

class LinkedList {
public:
    Node* first_elem;
    LinkedList(Node* first = nullptr) {
        first_elem = first;
    }

    void append(int val) {
        Node* new_node = new Node(val);

        if (first_elem == nullptr) {
            first_elem = new_node;

        } else {
            Node* temp = first_elem;
            while (temp->next_member != nullptr) {
                temp = temp->next_member;
            }
            temp->next_member = new_node;
        }
    }

    void push(int val) {
        Node* new_node = new Node(val);

        new_node->next_member = first_elem;
        first_elem = new_node;
    }

    void reverse() {
        Node* last = nullptr;
        Node* now = first_elem;
        Node* after = nullptr;

        while (now != nullptr) {
            after = now->next_member;
            now->next_member = last;
            last = now;
            now = after;
        }
        first_elem = last;
    }

    void pop() {
        if (first_elem != nullptr) {
            Node* temp = first_elem;
            first_elem = first_elem->next_member;

            delete temp;
        }
    }

    void sort() {
        Node* now = first_elem;
        
        while (now != nullptr) {
            Node* after = now->next_member;

            while (after != nullptr) {
                if (now->value > after->value) {
                int temp = now->value;
                    now->value = after->value;
                    after->value = temp;
                }
                after = after->next_member;
            }
            now = now->next_member;
        }
    }

    void insert(int position, int value) {
        Node* new_node = new Node(value);

        if (position == 0) {
            new_node->next_member = first_elem;
            first_elem = new_node;
        }
        Node* temp = first_elem;

        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next_member;
        }
        new_node->next_member = temp->next_member;
        temp->next_member = new_node;
    }

    int get_len() {
        int count = 0;
        Node* temp = first_elem;

        while (temp != nullptr) {
            count++;
            temp = temp->next_member;
        }
        return count;
    }

    void print_list() {
        Node* temp = first_elem;
        while (temp != nullptr) {
            cout << temp->value << " --- ";
            temp = temp->next_member;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    cout << "\n";
    cout << "(append) --- ";
    list.append(1);
    list.append(2);
    list.append(3);
    list.print_list();

    cout << "\n";
    cout << "(push) --- ";
    list.push(0);
    list.print_list();
    
    cout << "\n";
    cout << "(reverse) --- ";
    list.reverse();
    list.print_list();

    cout << "\n";
    cout << "(pop) --- ";
    list.pop();
    list.print_list();

    cout << "\n";
    cout << "(sort) --- ";
    list.sort();
    list.print_list();

    cout << "\n(insert) --- ";
    list.insert(2, 3);
    list.print_list();

    cout << "\n";
    cout << "(len) --- " << list.get_len() << endl;
    return 0;
} 