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
int del(node* &head, int data){
    int pos = 1;
    if(head == nullptr)
    return -1;
    if(head->data == data){
        node* temp = head;
        head = head->next;
        delete temp;
        return pos;
    }
    node* temp = head;
    while(temp != nullptr && temp->next->data != data){
        temp = temp->next;
        pos++;
    }
    if(temp != nullptr){
    node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return pos+1;
    }
    else{
        return -1;
    }
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
node* sort0s1s2s(node* head){
    node* zeros = nullptr;
    node* ones = nullptr;
    node* twos = nullptr;
    node * track = nullptr;
    node* new_head = nullptr;
    node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            if(zeros == nullptr){
                zeros = new node(0);
            }
            else{
                insertAtTail(zeros, 0);
            }
        }
        else if(temp->data == 1){
            if(ones == nullptr){
                ones = new node(1);
            }else{
                insertAtTail(ones, 1);
            }
        }
        else if(temp->data ==2){
            if(twos == nullptr){
                twos = new node(2);
            }else{
                insertAtTail(twos, 2);
            }
        }
        else{
            cout<<"Sorry unexpected input detected!"<<endl;
            return new_head;
        }
        temp = temp->next;
    }
    if(zeros != nullptr){
        new_head = zeros;
        track = zeros;
        while(track->next != nullptr){
            track = track->next;
        }
    }
    if(ones != nullptr){
        if(track == nullptr)
        new_head = ones;
        else
        track->next = ones;
        track = ones;
        while(track->next != nullptr){
            track = track->next;
        }
    }
    if(twos != nullptr){
        if(track == nullptr)
        new_head = twos;
        else
        track->next = twos;
        track = twos;
        while(track->next != nullptr){
            track = track->next;
        }
    }
    return new_head;
}

node* mergetwoSortedList(node* head1, node* head2){
    node* new_list = nullptr;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->data <= head2->data){
            if(new_list == nullptr){
                new_list = new node(head1->data);
            }else{
                insertAtTail(new_list, head1->data);
            }
            head1 = head1->next;
        }else{
            if(new_list == nullptr){
                new_list = new node(head2->data);
            }else{
                insertAtTail(new_list, head2->data);
            }
            head2 = head2->next;
        }
    }
        
        while(head1 != nullptr){
            if(new_list == nullptr){
                new_list = new node(head1->data);
            }else{
                insertAtTail(new_list, head1->data);
            }
            head1 = head1->next;
        }
        while(head2 != nullptr){
            if(new_list == nullptr){
                new_list = new node(head2->data);
            }else{
                insertAtTail(new_list, head2->data);
            }
            head2 = head2->next;
        }
        return new_list;
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
    int pos = del(head, 99);
    //cout<<"Element "
    pos == -1?cout<<"Sorry the element was not found.":cout<<"Element was deleted from the position "<<pos<<endl;
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
    node* node3 = new node(0);
    node* head3 = node3;
    node* node4 = new node(0);
    node* head4 = node4;
    for(int i = 0 ; i < 10 ; i++){
        if(i%3 == 0)
        insertAtTail(head3, 0);
        else if(i%2 == 0){
        //insertAtTail(head3, 1);
        }
        else
        insertAtTail(head3, 2);
    }
    for(int i = 0 ; i < 15 ; i++){
        if(i%5 == 0){
            insertAtTail(head4, 0);
        }else if(i%2 == 0){
            insertAtTail(head4, 1);
        }else{
            insertAtTail(head4, 2);
        }
    }
    cout<<"Before Sorting:- "<<endl;
    cout<<"First List: ";
    print(head3);
    cout<<"Second List: ";
    print(head4);
    head3 = sort0s1s2s(head3);
    head4 = sort0s1s2s(head4);
    cout<<"After Sorting"<<endl;
    if(head3 != nullptr){
        node* temp = head3;
        print(temp);
    }
    else{
        cout<<"Process terminated!"<<endl;
    }
    if(head4 != nullptr){
        node* temp = head4;
        print(temp);
    }
    cout<<"Let's Merge!"<<endl;
    node* merged = mergetwoSortedList(head3, head4);
    print(merged);
    return 0;
}