#include<iostream>
#include<queue>
#include<stack>
#include<list>

using namespace std;


queue<int> reverseFirstK(queue<int> &q, int k){
    if(k <= q.size()){
        int remain = q.size() - k;
        stack<int> st;
        list<int> li;
        for(int i = 0 ; i < k ; i++){
            st.push(q.front());
            q.pop();
        }
        for(int i = 0 ; i < k ; i++){
            q.push(st.top());
            st.pop();
        }
        for(int i = 0 ; i < remain ; i++){
            li.push_back(q.front());
            q.pop();
        }
        for(int i = 0 ; i < remain ; i++){
            q.push(li.front());
            li.pop_front();
        }
        return q;
    }else{
        return q;
    }
}
int main(){
    int qSize, k, element;
    cout<<"Enter the size of queue: ";
    cin>>qSize;
    cout<<"Enter the size of K: ";
    cin>>k;
    queue<int> q;
    for(int i = 0 ; i < qSize ; i++){
        cout<<"Enter the "<<(i+1)<<"th element: ";
        cin>>element;
        q.push(element);
    }
    reverseFirstK(q, k);
    return 0;
}