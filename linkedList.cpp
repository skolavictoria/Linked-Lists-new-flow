#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr){}
};

class LinkedList{
public:
    Node* head;
    
    LinkedList() : head(nullptr){}
    
    void append(int value){
        Node* newNode=new Node(value);
        if(!head){
            head=newNode;
            return;
        }
        Node* temp=head;
        while (temp->next) temp=temp->next;
        temp->next=newNode;
    }
    
    void push(int value){
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    
    void pop(){
        if (!head) return;
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    
    void insert(int position, int value){
        if(position==0){
            push(value);
            return;
        }
        Node* newNode=new Node(value);
        Node* temp=head;
        for(int i=0; temp && i < position - 1; i++){
            temp = temp->next;
        };
        if(!temp){
            return;
        };
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void del(int position){
        if(!head)return;
        if(position==0){
            pop();
            return;
        }
        Node* temp=head;
        for (int i=0; temp->next && i < position-1; i++) temp = temp->next;
        if (!temp->next) return;
        Node* toDelete=temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    
    Node* eject(int position){
        if(!head){
            return nullptr;
        };
        if(position == 0){
            Node* temp = head;
            head = head->next;
            return temp;
        };
        Node* temp = head;
        for (int i=0; temp->next && i<position-1; i++) {
            temp = temp->next;
        };
        if (!temp->next){
            return nullptr;
        };
        Node* toEject = temp->next;
        temp->next = temp->next->next;
        return toEject;
    }
    
    int get_len(){
        int count = 0;
        Node* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    void reverseLinkedList(){
        Node* prev=nullptr, *curr=head, *next=nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        };
        head=prev;
    }
    
    void sortLinkedList(){
        if(!head || !head->next){
            return;
        };
        bool swapped;
        Node* ptr1;
        Node* lptr=nullptr;
        do{
            swapped=false;
            ptr1=head;
            while(ptr1->next != lptr){
                if(ptr1->value > ptr1->next->value){
                    swap(ptr1->value, ptr1->next->value);
                    swapped=true;
                }
                ptr1 = ptr1->next;
            }
            lptr=ptr1;
        }while(swapped);
    }
    
    void printList(){
        Node* temp=head;
        while(temp){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    list.append(10);
    list.append(20);
    list.push(5);
    list.insert(1, 15);
    list.printList();
    
    list.pop();
    list.printList();
    
    list.del(1);
    list.printList();
    
    Node* ejected=list.eject(1);
    if(ejected){
        cout << "Ejected: " << ejected->value << endl;
    }
    list.printList();
    
    cout << "Length: " << list.get_len() << endl;
    
    list.reverseLinkedList();
    list.printList();
    
    list.sortLinkedList();
    list.printList();
    
    return 0;
}