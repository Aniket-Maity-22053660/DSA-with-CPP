#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void insertBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    insertBottom(st, element);
    st.push(top);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertBottom(st, top);
}

void interLeave(queue<int> &q){
    int mid = q.size()/2;
    stack<int> st;
    for(int i = 0 ; i < mid ; i++){
        st.push(q.front());
        q.pop();
    }
    reverseStack(st);
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){
    int size, element;
    queue<int> q;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter the "<<(i+1)<<"th element: ";
        cin>>element;
        q.push(element);
    }
    interLeave(q);
    cout<<"After interleaving : ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<'\n';
}