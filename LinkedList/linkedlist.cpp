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
        //add elem after the last elem
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
 // add elem at the beggining of the list 
        Node* newNode = new Node(value);
        newNode-> add_next_member(first_elem);
        first_elem = newNode;
    }

    void pop(){
  // get the first elem of the list and than delete it
        if(first_elem == nullptr){
            return;
        }
        Node* temp = first_elem;
        first_elem = first_elem->get_next_member();
        delete temp;
        
    }

    void del(int position){
   // delete elem that is placed in positon
        if(first_elem == nullptr){
            return;
        }
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

    void sort(){
        if (first_elem == nullptr || first_elem->get_next_member() == nullptr){
            return;
        }
    
        bool swapped;
        do {
            swapped = false;
            Node* current = first_elem;
            Node* prev = nullptr;
    
            while (current->get_next_member() != nullptr) {
                Node* next = current->get_next_member();
                if (current->get_value() > next->get_value()) {
                    // Меняем местами
                    if (prev != nullptr) {
                        prev->add_next_member(next);
                    } else {
                        first_elem = next;
                    }
                    current->add_next_member(next->get_next_member());
                    next->add_next_member(current);
                    
                    swapped = true;
                }
                prev = current;
                current = current->get_next_member();
            }
        } while (swapped);
    }
    

    void show(){
        Node* current = first_elem;

        while(current != nullptr){
            cout << current->get_value() << " ";
            current = current->get_next_member();

        }
        cout << endl;
    }

    void Reverse(){
        // ne ebu kak sdelat
    }
};

int main()
{
    Node* node0 = new Node(12);
    Node* node1 = new Node(2);
    Node* node2 = new Node(12);
    node0->add_next_member(node1);
    LinkedList llist = LinkedList(node0);
    //cout << llist.first_elem->get_value() << endl;
    //cout << llist.first_elem->get_next_member()->get_value() << endl;
    //cout << llist.get_len() << endl;
    llist.insert(1,123);
    llist.show();
    llist.append(12);
    llist.show();
    llist.push(123);
    llist.show();
    llist.pop();
    llist.show();
    llist.del(2);
    llist.show();
}