#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node* next_member = nullptr;
public:
    Node(int value) : value(value) {}
    void add_next_member(Node* ptr) { next_member = ptr; }
    int get_value() { return value; }
    Node* get_next_member() { return next_member; }
};

class LinkedList {
public:
    Node* head = nullptr;
    LinkedList(Node* head) : head(head) {}

    void push(int value) {
        Node* new_node = new Node(value);
        new_node->add_next_member(head);
        head = new_node;
    }

    void append(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->get_next_member()) {
            temp = temp->get_next_member();
        }
        temp->add_next_member(new_node);
    }

    void insert(int position, int value) {
        if (position == 0) {
            push(value);
            return;
        }

        Node* new_node = new Node(value);
        Node* temp = head;

        for (int i = 0; temp && i < position - 1; i++) {
            temp = temp->get_next_member();
        }

        if (!temp) {
            cout << "Insert error\n";
            delete new_node;
            return;
        }

        new_node->add_next_member(temp->get_next_member());
        temp->add_next_member(new_node);
    }

    void display() {
        Node* mmbr = head;
        while (mmbr) {
            cout << mmbr->get_value() << " -> ";
            mmbr = mmbr->get_next_member();
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Node* first = new Node(10);
    LinkedList list(first);

    list.push(5);
    list.append(20);
    list.insert(1, 15);
    list.insert(10, 50);

    list.display(); 

    return 0;
}
