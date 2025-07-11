#include<iostream>
#include "Stack.h"
#include<deque>
using namespace std;


int main(){
    cout<<"Enter the number of elements: ";
    int size, element, middle;
    cin>>size;
    Stack<int> st(size);
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter the "<<(i+1)<<"th element: ";
        cin>>element;
        cout<<element<<endl;
        st.push(element);
    }

    middle = st.size / 2;
    deque<int> dq;
    deque<int>::iterator it;
    for (int i = 0 ; i <= middle ; i++){
        dq.push_front(st.pop());
    }


    for(it = dq.begin()+1 ; it != dq.end() ; it++){
        st.push(*it);
    }
    cout<<"After deleting the middle elements:- "<<endl;
    for(int i = 0 ; i < st.size-1 ; i++){
        cout<<st.pop()<<endl;
    }
    
    return 0;
}