#include<iostream>
#include "Stack.h"

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
int main(){
    int size, element;
    cout<<"Enter the stack size: ";
    cin>>size;

    Stack<int> st(size);
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter the "<<i+1<<"nth element: ";
        cin>>element;
        insertAtBottom(st, element);
    }
    cout<<"Printing stack-----"<<endl;
    for (int i = 0 ; i < size ; i++){
        cout<<st.pop()<<endl;
    }
    return 0;
}