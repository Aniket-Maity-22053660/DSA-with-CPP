#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
    node* next;
};
void insertAtHead(node* &head, int data){
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(node* head, int data){
    node* temp = new node(data);
    while(head->next != nullptr){
        head = head->next;
    }
    head->next = temp;
}
void insertAtPos(node* &head, int pos, int data){
    node* temp = new node(data);
    node* ptr = head;
    int init = 1;
    while(init < pos-1){
        ptr = ptr->next;
        init++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void print(node* head){
    
    while(head != nullptr){
        cout<<head->data;
        if(head->next != nullptr){
            cout<<", ";
        }
        else{
            cout<<'\n';
        }
        head = head->next;
    }
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
    node* temp = head;
    while(temp->next->data != data){
        temp = temp->next;
    }
    node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
}
void reverse(node* &head){
    node* back = nullptr;
    node* middle = head;
    node* front = middle->next;
    while(middle != nullptr){
        middle->next = back;
        back = middle;
        middle = front;
        if(front != nullptr)
        front = front->next;
    }
    head = back;

}

int main(){
    node *node1 = new node(12);
    node *head = node1;
    cout<<head->data<<endl<<head->next<<endl;
    insertAtHead(head, 45);
    cout<<head->data<<endl<<head->next<<endl;
    print(head);
    insertAtHead(head, 99);
    print(head);
    insertAtTail(head, 111);
    print(head);
    insertAtTail(head, 999);
    print(head);
    insertAtHead(head, 699);
    print(head);
    insertAtPos(head, 2, 20);
    print(head);
    del(head, 99);
    print(head);
    reverse(head);
    print(head);
    return 0;
}