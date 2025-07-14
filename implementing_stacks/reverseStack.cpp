#include<iostream>
#include "Stack.h"

void printStack(Stack<int> st){
    if(st.isEmpty()){
        return;
    }
    int top = st.top();
    cout<<top<<endl;
    st.pop();
    printStack(st);
    st.push(top);
}
void insertAtBottom(Stack<int> &st, int element){
    if(st.isEmpty()){
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(top);
}
void reverseStack(Stack<int> &st){
    if(st.isEmpty()){
        return;
    }
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}
int main(){
    int size, element;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    Stack<int> st(size);
    for (int i = 0 ; i < size ; i++){
        cout<<"Enter the "<<(i+1)<<"th element: ";
        cin>>element;
        st.push(element);
    }
    cout<<"Original given stack------- "<<endl;
    printStack(st);
    cout<<"After reversal of the stack--------"<<endl;
    reverseStack(st);
    printStack(st);
    return 0;
}