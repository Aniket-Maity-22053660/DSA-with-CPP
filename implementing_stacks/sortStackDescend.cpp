#include<iostream>
#include "Stack.h"

void printStack(Stack<int> &st){
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
    if(st.isEmpty() || (!st.isEmpty() && st.top() > element)){
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(top);
}
void sortStack(Stack<int> &st){
    if(st.isEmpty()){
        return;
    }
    int top = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, top);
}
int main(){
    int size, element;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    Stack<int> st(size);
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter the "<<(i+1)<<"th element: ";
        cin>>element;
        st.push(element);
    }
    cout<<"Original stack------- "<<endl;
    printStack(st);
    cout<<"After sorting in Descending order--------"<<endl;
    sortStack(st);
    printStack(st);

    return 0;
}