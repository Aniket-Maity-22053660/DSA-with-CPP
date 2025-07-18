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
    temp->prev = head;
}
void insertAtPos(node* &head, int data, int pos){
    if(pos == 1){
        insertAtHead(head ,data);
        return;
    }
    int init = 1;
    node* tempPtr = head;
    while(init < pos-1 && tempPtr != nullptr){
        tempPtr = tempPtr->next;
        init++;
    }
    if(tempPtr != nullptr  && tempPtr->next != nullptr){
    node* ptr = tempPtr->next;
    node* temp = new node(data);
    ptr->prev = temp;
    temp->next = ptr;
    tempPtr->next = temp;
    }
    else{
        insertAtTail(head, data);
    }
    return;
}
void del(node* &head, int data) {
    if (head == nullptr) return;

    // Case 1: delete head
    if (head->data == data) {
        node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    node* tempPtr = head;
    // Traverse and find the node before the one to be deleted
    while (tempPtr->next != nullptr && tempPtr->next->data != data) {
        tempPtr = tempPtr->next;
    }

    if (tempPtr->next == nullptr) {
        // Node with given data not found
        return;
    }

    node* temp = tempPtr->next;
    tempPtr->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = tempPtr;
    }
    delete temp;
}


void reverse(node* &head) {
    
    if (head == nullptr || head->next == nullptr) return;

    node* current = head;
    node* temp = nullptr;

    // Traverse and swap prev and next for all nodes
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // After the loop, temp is the previous node of the new head
    if (temp != nullptr) {
        head = temp->prev;
    }

        
        /*
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        while(temp != nullptr){
            cout<<temp->data;
            if(temp->prev != nullptr){
                cout<<", ";
            }else{
                cout<<'\n';
            }
            temp = temp->prev;
        }
            */
}

bool isCircular(node* head){
    node* temp = head;
    do{
        temp = temp->next;
        if(temp == nullptr){
            return false;
        }
    }while(temp != head);
    return true;
}


void print(node* head){
    while(head != nullptr){
        cout<<head->data;
        if(head->next != nullptr)
        {cout<<", ";}
    else{
        cout<<'\n';
    }
    head = head->next;
    }
}
int main(){
    node* node1 = new node(20);
    node* head = node1;
    insertAtHead(head, 10);
    insertAtHead(head, 30);
    print(head);
    /*reverse(head);
    insertAtPos(head, 50, 1);
    print(head);
    reverse(head);
    del(head, 50);
    reverse(head);
    print(head);
    */
    reverse(head);
    print(head);
    insertAtPos(head, 50, 1);
    print(head);
    del(head, 30);
    reverse(head);
    print(head);
    insertAtTail(head, 90);
    print(head);
    insertAtPos(head, 100, 90);
    reverse(head);
    print(head);
    del(head, 10);
    print(head);
    reverse(head);
    print(head);
    cout<<"Is this list circular? "<<isCircular(head)<<endl;
    return 0;
}