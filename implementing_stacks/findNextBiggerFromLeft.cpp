#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<stack>
using namespace std;

int main(){
    vector<int> vec = {2,3,4,7,5,2};
    stack<int> st;
    list<int> li;
    st.push(INT_MAX);
    for(int i = 0 ; i < vec.size() ; i++){
        while(st.top() < vec.at(i)){
            st.pop();
        }
        li.push_back(st.top());
        st.push(vec.at(i));
    }
    vector<int>:: iterator it1;
    list<int>:: iterator it2;

    cout<<endl<<"Given array: ";
    for(it1 = vec.begin() ; it1 != vec.end() ; it1++){
        cout<<*it1<<" ";
    }
    cout<<endl<<"Array of next bigger elements from left side: ";
    for(it2 = li.begin() ; it2 != li.end() ; it2++){
        cout<<*it2<<" ";
    }
    cout<<'\n';
    
    return 0;
}