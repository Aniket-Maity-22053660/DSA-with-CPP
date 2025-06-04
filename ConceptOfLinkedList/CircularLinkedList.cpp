#include<iostream>

using namespace std;
class node{
    public:
    int data;
    node*next = this;
    node(int data){
        this->data = data;
    }
};

void insertAtTail(node* &tail, int data){
    node* temp = new node(data);
    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;

}
void insertAtHead(node* const &tail, int data){
    node* temp = new node(data);
    temp->next = tail->next;
    tail->next = temp;
}
void insertAtPos(node* &tail, int data, int pos){
    if(pos == 1){
        insertAtHead(tail, data);
        return;
    }
    node* current = tail->next;
    while(pos != 2 && current->next != tail->next){
        current = current->next;
        pos--;
    }
    
    if(current->next != tail->next){
    node* temp = new node(data);
    temp->next = current->next;
    current->next = temp;
    }else{
        insertAtTail(tail, data);
    }
    return;


}
void print(node* const &tail) {
    if (tail == nullptr) return;

    node* current = tail->next; // Start from head
    do {
        cout << current->data;
        current = current->next;
        if (current != tail->next) {
            cout << ", ";
        } else {
            cout << '\n';
        }
    } while (current != tail->next);
}

int main(){
    node* node1 = new node(19);
    node* tail = node1;
    print(tail);
    insertAtTail(tail, 90);
    print(tail);
    insertAtHead(tail, 55);
    print(tail);
    insertAtPos(tail, 100,5);
    print(tail);
    return 0;
}