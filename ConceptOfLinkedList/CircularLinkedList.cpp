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
void del(node* tail, int data){
    node* ptr = tail->next;
    if(ptr->data == data){
        node* temp = ptr;
        temp = temp->next;
        tail->next = temp;
        ptr->next = nullptr;
        delete ptr;
        return;
    }else{
    do{
        if(ptr->next->data == data){
             break;
        }
        ptr = ptr->next;
    }while(ptr != tail->next);
    node* temp = ptr->next;
    ptr->next = temp->next;
}
}
void reverse(node* &tail){
    node* end = tail->next;
    node* back = tail;
    node* middle = tail->next;
    node* front = tail->next->next;

    do{
        middle->next = back;
        back = middle;
        middle = front;
        {
        front = front->next;
        }
    }while(middle != end);
    tail = middle;
}

node* findMiddle(node*tail){
    node* ptr = tail->next;
    if(tail == nullptr){
        return nullptr;
    }
    else if(tail->next == tail){
        return tail;
    }else if(tail->next->next == tail){
        return tail->next;
    }else{
        node* first = tail->next;
        node* second = tail->next;
    do{
        first = first->next;
        second = second->next->next;

    }while(second->next != tail->next && second->next->next != tail->next);
    if(second->next == tail->next){
        return first;
    }else{
        return first->next;
    }
}
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
    del(tail, 19);
    print(tail);
    del(tail, 55);
    print(tail);
    insertAtPos(tail, 599, 90);
    print(tail);
    insertAtPos(tail, 699, 2);
    print(tail);
    reverse(tail);
    print(tail);
    cout<<(findMiddle(tail))->data<<endl;
    insertAtPos(tail, 10, 99);
    print(tail);
    cout<<(findMiddle(tail))->data<<endl;
    cout<<"Is it a circular list? "<<isCircular(tail->next)<<endl;
    return 0;
}