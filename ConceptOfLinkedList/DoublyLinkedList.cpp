#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int data){
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};
void insertAtHead(node* &head, int data){
    node* temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(node* head, int data){
    node* temp = new node(data);
    while(head->next != nullptr){
        head = head->next;
    }
    head->next = temp;
    temp->prev = head;;
}
void del(node* &head, int data){
    if(head == nullptr)
    return;
    if(head->data == data){
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while(head->next->data != data){
        head = head->next;
    }
    node* temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;
    delete temp;
    return;
}
void print(node* head){
    while(head != nullptr){
        cout<<head->data;
        if(head->next != nullptr)
        cout<<", ";
    else{
        cout<<'\n';
    }
    head = head->next;
    }
}
int main(){
    node* node1 = new node(20);
    node* head = node1;
    print(head);
    insertAtHead(head, 30);
    print(head);
    insertAtTail(head, 50);
    print(head);
    del(head, 20);
    print(head);
    del(head, 30);
    print(head);
    return 0;
}