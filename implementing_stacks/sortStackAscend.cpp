#include<iostream>
#include "Stack.h"

void printStack(Stack<int> st){
    if(st.isEmpty()){
        return;
    }
    int top = st.top();
    st.pop();
    cout<<top<<endl;
    printStack(st);
    st.push(top);
}

void sortedInsert(Stack<int> &st, int element){
    if(st.isEmpty() || (!st.isEmpty() && st.top() < element)){
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(top);
}
void sortStackAscend(Stack<int> &st){
    if(st.isEmpty()){
        return;
    }
    int top = st.top();
    st.pop();
    sortStackAscend(st);
    sortedInsert(st, top);
}
int main(){
    int size, element;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    Stack<int> st(size);
    for(int i = 0 ; i < size ; i++){
        cout<<"enter the "<<(i+1)<<"th element: ";
        cin>>element;
        st.push(element);
    }
    cout<<"Original stack------"<<endl;
    printStack(st);
    sortStackAscend(st);
    cout<<"After sorting in ascending order--------"<<endl;
    printStack(st);
    return 0;
}