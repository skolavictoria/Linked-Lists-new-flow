#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node* next_member = nullptr;

public:
    Node(int value) : value(value) {}
    void add_next_member(Node* ptr)
    {
        next_member = ptr;
    }
    int get_value()
    {
        return value;
    }
    Node* get_next_member()
    {
        return next_member;
    }
};

class LinkedList
{
public:
    Node* first_elem = nullptr;
    LinkedList(Node* first_elem) : first_elem(first_elem) {}

    void insert(int position, int value)
    {
        Node* newNode = new Node(value);

        if (position == 0)
        {
            newNode->add_next_member(first_elem);
            first_elem = newNode;
            return;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);

        if (first_elem == nullptr) {
            first_elem = newNode;
            return;
        }

        Node* current = first_elem;
        while (current->get_next_member() != nullptr) {
            current = current->get_next_member();
        }
    
        current->add_next_member(newNode);
    }

    void push(int value){
        Node* newNode = new Node(value);
        newNode-> add_next_member(first_elem);
        first_elem = newNode;
    }

    void pop(){

        Node* temp = first_elem;
        first_elem = first_elem->get_next_member();
        delete temp;
        
    }

    void del(int position){
    
        if(position == 0){
            Node* temp = first_elem;
            first_elem = first_elem->get_next_member();
            delete temp;
            return;
        }
        Node* current = first_elem;
        Node* tmp = nullptr;
        int i = 0;
        while(current != nullptr && i < position){
            tmp = current;
            current = current->get_next_member();
            i++; 
        }
        tmp -> add_next_member(current->get_next_member());
        delete current;
    }

    int get_len(){
        int i = 0;
        Node* current = first_elem;
        while (current != nullptr){
            i++;
            current = current->get_next_member();
        }
        return i;
    }

    void sort() {
        if (first_elem == nullptr) {
            return;
        }
    
        bool swapped;
        do {
            swapped = false;
            Node* current = first_elem;
            Node* back = nullptr;
    
            while (current->get_next_member() != nullptr) {
                Node* next = current->get_next_member();
                if (current->get_value() > next->get_value()) {
                    current->add_next_member(next->get_next_member());
                    next->add_next_member(current);
    
                    if (back == nullptr) {
                        first_elem = next;
                    } else {
                        back->add_next_member(next);
                    }
                    swapped = true;
                }
                back = (swapped ? next : current);
                current = next;
            }
        } while (swapped);
    }
    
};

int main()
{
    Node* node0 = new Node(12);
    Node* node1 = new Node(123);
    node0->add_next_member(node1);
    LinkedList llist = LinkedList(node0);
    cout << llist.first_elem->get_value() << endl;
    cout << llist.first_elem->get_next_member()->get_value() << endl;
    cout << llist.get_len() << endl;
    llist.insert(1,123);
    llist.append(12);
    llist.push(123);
    llist.pop();
    llist.del(2);
}