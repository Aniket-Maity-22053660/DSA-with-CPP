#include<iostream>
#include "Stack.h"
#include<vector>
#include<list>
using namespace std;

int main(){
    vector<int> vec = {3, 5, 7, 3, 9, 1};
    Stack<int> st(vec.size());
    list<int> ans;
    st.push(-1);
    for(int i = vec.size()-1 ; i >= 0 ; i--){
        while(st.top() > vec.at(i)){
            st.pop();
        }
        ans.push_front(st.top());
        st.push(vec[i]);
    }

    vector<int>:: iterator it;
    list<int>:: iterator it1;
    cout<<"Actual array: ";
    for(it = vec.begin() ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<'\n';
    cout<<"Array of next smaller element from right: ";
    for(it1 = ans.begin() ; it1 != ans.end() ; it1++){
        cout<<*it1<<" ";
    }
    cout<<'\n';
    return 0;
}