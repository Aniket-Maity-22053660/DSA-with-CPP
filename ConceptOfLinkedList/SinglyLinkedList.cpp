#include<iostream>
#include<map>
#include<list>
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
            cout<<" -> ";
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
node* reverseInKthStage(node* head, int cnt){
    node* temp = head;
    int count = 0;
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    if(count < cnt){
        return head;
    }
    
    node* back = nullptr;
    node* current = head;
    node* front = nullptr;
    count = 0;
    while(current != nullptr && count < cnt){
        front = current->next;
        current->next = back;
        back = current;
        current = front;
        count++;
    }
    if(front != nullptr){
        head->next = reverseInKthStage(front, cnt);
    }
    return back;
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

bool isLoopPresent(node* head){
    map<node*, bool> visited;
    node* temp = head;
    while(temp != nullptr){
        if(visited[temp] != true){
        visited[temp] = true;
        }
    else{
        return true;
    }
        temp = temp->next;
    }
    return false;

}

node* floydsCycleDetection(node* head){
    
    if(head == nullptr){
        return nullptr;
    }
    node*slow = head;
    node*fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return slow;
        }
    }
    return nullptr;
}
void createLoop(node* head, int pos){
    node* temp = head;
    node* flag = nullptr;
    while(temp->next != nullptr){
        if(pos == 1){
            flag = temp;
        }
        temp = temp->next;
        pos--;
    }
    temp->next = flag;
}
node* getLoopNode(node* head){
    node* temp2 = floydsCycleDetection(head);
    if(temp2){
    node* temp1 = head;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    }else{
        return nullptr;
    }
    return temp2;
}
void breakTheLoop(node* head){
    node* temp2 = floydsCycleDetection(head);
    if(temp2){
        node* temp1 = head;
        node* temp3 = nullptr;
        while(temp1 != temp2){
            temp3 = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp3->next = nullptr;
    }else{
        return;
    }
    return;
}
void deleteDuplicates(node* &head){
    if(head == nullptr){
        return;
    }
    node* prev = head;
    node* temp = head;
    list<node*> li;
    int j = 0;
    while(temp != nullptr && temp->next != nullptr){
        temp = temp->next;
        if(prev->data == temp->data){
            prev->next = temp->next;
            li.push_back(temp); 
        }
        else{
            prev = temp;
        }
    }
    list<node*>:: iterator it = li.begin();
    for(; it != li.end() ; it++){
        delete (*it);
    }
    li.clear();
}
void rmvDuplicatesFromUnsortedList(node* &head){
    if(head != nullptr && head->next != nullptr){
    node* temp = head->next;
    node* prev = head;
    map<int, bool> mp;
    mp.insert({head->data, true});
    while(temp != nullptr){
        if(mp.count(temp->data) > 0){
            prev->next = temp->next;
            node*  temp1 = temp;
            temp = temp->next;
            delete temp1;
        }
        else{
        mp.insert({temp->data, true});
        prev = temp;
        temp = temp->next;
        }
    }
    }else{
        return;
    }
}

list<node*> splitListInKparts(node* head, int k){
    list<node*> li; 
    if(head != nullptr){
        cout<<"After splitting the list in upto "<<k<<" nodes in each part:-"<<endl;
    node* front = head;
    node* back = head;
    
    int count;
    while(front != nullptr && back != nullptr){
        count = k;
    while(front->next != nullptr && count > 1){ 
        front = front->next;
        count--;
    }
    node* temp = front; 
    front = front->next;
    temp->next = back;
    li.push_back(temp); 
    back = front;
    }
    }
    else{
        cout<<"Sorry! there are nodes in the list."<<endl;
    }
    return li;

}
void printCircular(node* const &tail) {
    if (tail == nullptr) return;

    node* current = tail->next; // Start from head
    do {
        cout << current->data;
        current = current->next;
        if (current != tail->next) {
            cout << " -> ";
        } else {
            cout << '\n';
        }
    } while (current != tail->next);
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
    head = reverseInKthStage(head, 7);
    print(head);
    cout<<"Is this list circular? "<<isCircular(head)<<endl;
    cout<<"Is there any loop? "<<isLoopPresent(head)<<endl;
    cout<<"Using floyd's cycle detection algorithm? ";
    floydsCycleDetection(head)?cout<<"Yes! "<<"The loop started at "<<(floydsCycleDetection(head))->data<<"."<<endl:cout<<"No!"<<endl;
    print(head);
    insertAtTail(head, 30);
    insertAtTail(head, 35);
    print(head);
    createLoop(head, 3);
    //print(head);
    floydsCycleDetection(head)?cout<<"Yes! "<<"The loop started at "<<(getLoopNode(head))->data<<"."<<endl:cout<<"No!"<<endl;
    breakTheLoop(head);
    cout<<"Using floyd's cycle detection algorithm? ";
    floydsCycleDetection(head)?cout<<"Yes! "<<"The loop started at "<<(getLoopNode(head))->data<<"."<<endl:cout<<"No!"<<endl;
    print(head);
    node* node2 = new node(1);
    node* head1 = node2;
    insertAtTail(head1, 1);
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    
    print(head1);
    //deleteDuplicates(head1);
    rmvDuplicatesFromUnsortedList(head1);
    cout<<"After deleting the duplicate elements: ";
    print(head1);
    list<node* > splitted = splitListInKparts(head, 2);
    list<node*>:: iterator it = splitted.begin();
    for(;it != splitted.end() ; it++){
        printCircular(*it);
    }
       
    return 0;
}