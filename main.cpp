#include <iostream>
#include <string>
using namespace std;
class Node{
    private:
        int value;
        Node* next_member =nullptr;
    public:
        Node(int value) : value(value){};
        void add_next_member(Node* ptr){
            next_member = ptr;
        }
        int get_value(){
            return value;
        }
        Node* get_next_member(){
            return next_member;
        }
};

class LinkedList{
    public:
    Node* first_elem = nullptr;
    LinkedList(Node* first_elem): first_elem(first_elem){};

    void insert(int p, int v) {
    Node* n_n = new Node(v);  // n_n - new node, v - value, p - position
    if (p == 0) {
        n_n->add_next_member(first_elem); // positioning as first node (works if List empty)  
        first_elem = n_n;  
        return;
    }

    Node* current = first_elem;
    for (int i = 0; current != nullptr && i < p - 1; i++) {
        current = current->get_next_member();  

    if (current != nullptr) {
        n_n->add_next_member(current->get_next_member());  
        current->add_next_member(n_n);  
    }
}
};
    void append(int v) {
    Node* n_n = new Node(v);  // n_n - new node, v - value
    if (first_elem == nullptr) {
        first_elem = n_n;  
        return;
    }

    Node* current = first_elem;
    while (current->get_next_member() != nullptr) {
        current = current->get_next_member();  
    }

    current->add_next_member(n_n);  
}

void push(int v) {
    Node* n_n = new Node(v);  // n_n - new node, v - value
    n_n->add_next_member(first_elem);  
    first_elem = n_n;
}
void pop() {
    if (first_elem == nullptr) return;
    Node* temp = first_elem;
    first_elem = first_elem-> get_next_member();
    delete temp;
}
void del(int p) {
    if (first_elem == nullptr) return;

    if (p == 0) {
        pop();
        return;
    }
    Node* current = first_elem;
    for (int i = 0; current != nullptr && i < p -1; i++) {
        current = current->get_next_member();
    }
    if (current != nullptr && current->get_next_member() != nullptr) {
        Node* temp = current->get_next_member();
        current->add_next_member(temp->get_next_member());
        delete temp;
    }
}
int get_len(){
    int l = 0; //l - lenght
    Node* current = first_elem;
    while (current != nullptr) {
        l++;
        current = current->get_next_member();
    }
    return l;
}

};

int main()
{

}