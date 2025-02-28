#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}

    void add_next_member(Node* node) {
        this->next = node;
    }

    Node* get_next_member() {
        return this->next;
    }

    int get_value() {
        return this->value;
    }
};

class LinkedList {
public:
    Node* first_elem = nullptr;
    LinkedList(Node* first_elem) : first_elem(first_elem) {}

    void insert(int position, int value) {
        Node* new_node = new Node(value);
        if (position == 0) {
            new_node->add_next_member(first_elem);
            first_elem = new_node;
            return;
        }

        Node* current = first_elem;
        int index = 0;

        while (current != nullptr && index < position - 1) {
            current = current->get_next_member();
            index++;
        }

        if (current != nullptr) {
            new_node->add_next_member(current->get_next_member());
            current->add_next_member(new_node);
        }
    }

    void append(int d) {
        Node* n = first_elem;

        if (n == nullptr) {
            first_elem = new Node(d);
            return;
        }

        while (n->get_next_member() != nullptr) {
            n = n->get_next_member();
        }
        Node* new_node = new Node(d);
        n->add_next_member(new_node);
    }

    void push(int value) {
        Node* new_node = new Node(value);
        new_node->add_next_member(first_elem);
        first_elem = new_node;
    }

    void pop() {
        if (first_elem != nullptr) {
            Node* temp = first_elem;
            first_elem = first_elem->get_next_member();
            delete temp;
        }
    }

    void del(int position) {
        if (first_elem == nullptr) {
            return;
        }

        if (position == 0) {
            Node* temp = first_elem;
            first_elem = first_elem->get_next_member();
            delete temp;
            return;
        }

        Node* current = first_elem;
        int index = 0;

        while (current != nullptr && index < position - 1) {
            current = current->get_next_member();
            index++;
        }

        if (current == nullptr || current->get_next_member() == nullptr) {
            return;
        }

        Node* next = current->get_next_member()->get_next_member();
        delete current->get_next_member();
        current->add_next_member(next);
    }

    void sort() {
        if (!first_elem || !first_elem->get_next_member()) {
            return;
        }
    }
};

int main() {
    Node* node0 = new Node(12);
    Node* node1 = new Node(123);
    node0->add_next_member(node1);
    LinkedList llist = LinkedList(node0);
    cout << llist.first_elem->get_value() << endl;
    cout << llist.first_elem->get_next_member()->get_value() << endl;

    LinkedList llist1 = LinkedList(new Node(0));
    llist1.append(10);
    llist1.append(20);

    llist1.del(1);

    Node* member = llist1.first_elem;
    while (member != nullptr) {
        cout << member->get_value() << endl;
        member = member->get_next_member();
    }
}
