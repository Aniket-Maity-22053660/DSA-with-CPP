#include<iostream>
#include "Queue.h"

int main(){
    Queue<int> q(9);
    q.push(3);
    q.push(4);
    q.push(45);
    cout<<"Front: "<<q.Front()<<endl;
    cout<<"Rear: "<<q.Rear()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
   // cout<<q.pop()<<endl;
    return 0;
}
