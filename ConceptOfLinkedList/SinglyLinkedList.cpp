#include<iostream>
#include<map>
#include<list>
#include<climits>
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
int createLoop(node* head, int pos){
    node* temp = head;
    node* flag = nullptr;
    int keep = pos;
    while(temp->next != nullptr){
        if(pos == 1){
            flag = temp;
        }
        temp = temp->next;
        pos--;
    }
    temp->next = flag;
    return keep;
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
int breakTheLoop(node* head){
    node* temp2 = floydsCycleDetection(head);
    node* temp3 = nullptr;
    if(temp2){
        node* temp1 = head;
        while(temp1 != temp2){
            temp3 = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp3->next = nullptr;
    }else{
        return INT_MIN;
    }
    return temp3->data;
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
node* findMiddle(node* head){
    if(head == nullptr)
    return nullptr;
    node* fast = head;
    node* slow = head;

    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* reverseAfterK(node* head){
    if(head == nullptr || head->next == nullptr)
    return nullptr;
    node* middle = head->next;
    node* prev = nullptr;
    node* front = middle;

    while(middle != nullptr){
        front = front->next;
        middle->next = prev;
        prev = middle;
        middle = front;
    }
    return prev;

}
bool checkPalindrome(node* head){
    node* middle = findMiddle(head);
    node* second = reverseAfterK(middle);

    while(second != nullptr){
        if(head->data != second->data){
            return false;
        }
        head = head->next;
        second = second->next;
    }
    return true;
}
node* addTwoLinkedList(node* list1, node* list2){
    int carry = 0;
    node* head1 = list1;
    node* head2 = list2;

    node* prev = nullptr;
    node* mid = head1;
    node* front = head1;

    while(mid != nullptr){
        front = front->next;
        mid->next = prev;
        prev = mid;
        mid = front;
    }
    node* tail1 = prev;
    prev = nullptr;
    mid = head2;
    front = head2;
    while(mid != nullptr){
        front = front->next;
        mid->next = prev;
        prev = mid;
        mid = front;
    }
    node* tail2 = prev;
    node* sum = nullptr;
    while(tail1 != nullptr && tail2 != nullptr){ 
        int total = (tail1->data + tail2->data) + carry;
        int add = total % 10;
        
        if(sum == nullptr){
            sum = new node(add);
        }else{
            insertAtHead(sum, add);
        }
        carry = total / 10;
        tail1 = tail1->next;
        tail2 = tail2->next;
    }
    while(tail1 != nullptr){
        int total = tail1->data + carry;
        int add = total % 10;
        if(sum == nullptr){
            sum = new node(add);
        }
        else{
            insertAtHead(sum, add);
        }
        carry = total / 10;
        tail1 = tail1->next;
    }

    while(tail2 != nullptr){
        int total = tail2->data + carry;
        int add = total % 10;
        if(sum == nullptr){
            sum = new node(add);
        }else{
            insertAtHead(sum, add);
        }
        carry = total / 10;
        tail2 = tail2->next;
    }
    if(carry != 0){
        insertAtHead(sum, carry);
    }
    return sum;
}
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, int data){
        if(head == nullptr)
        {
            Node* temp = new Node(data);
            head = temp;
            return;
        }
        Node* temp = new Node(data);
        Node* temp1 = head;
        while(temp1->next != nullptr){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
        return nullptr;
        Node* new_node = nullptr;
        Node* temp = head;
        
        while(temp != nullptr){
            insertAtTail(new_node, temp->val);
            temp = temp->next;
        }
        map<Node*, Node*> mp;
        temp = head;
        Node* temp1 = new_node;
        while(temp != nullptr && temp1 != nullptr){
            mp[temp] = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp = new_node;
        temp1 = head;
        while(temp != nullptr){
            temp->random = mp[temp1->random];
            temp = temp->next;
            temp1 = temp1->next;
        }
        return new_node;
    }
};
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
    int pos1 = createLoop(head, 3);
    cout<<"A loop was created at position "<<pos1<<"!"<<endl;
    //print(head);
    floydsCycleDetection(head)?cout<<"Yes! "<<"The loop started at "<<(getLoopNode(head))->data<<"."<<endl:cout<<"No!"<<endl;
    int pos2 = breakTheLoop(head);
    pos2 != INT_MIN ? cout<<"The loop was successfully broken with the element "<<pos2<<"!"<<endl : cout<<"Failed to break the loop!"<<endl;
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
    node* node5 = new node(90);
    node* head5 = node5;
    insertAtTail(head5, 2);
    insertAtTail(head5, 3);
    insertAtTail(head5, 2);
    insertAtTail(head5, 1);
    checkPalindrome(head5) ? cout<<"Yes! this list is a palindrome."<<endl : cout<<"This list is not a palindrome."<<endl;
    node* node6 = new node(9);
    node* head6 = node6;
    insertAtTail(head6, 9);
    insertAtTail(head6, 9);
    node* node7 = new node(9);
    node* head7 = node7;
    insertAtTail(head7, 9);
    insertAtTail(head7, 9);
    cout<<"LinkedList-1: ";
    print(head6);
    cout<<"LinkedList-2: ";
    print(head7);
    node* sum = addTwoLinkedList(head6, head7);
    cout<<"SUM: ";
    print(sum);
    
    return 0;
}