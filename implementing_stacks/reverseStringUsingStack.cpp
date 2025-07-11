#include<iostream>
#include "Stack.h"
using namespace std;

int main(){
    string str = "Aniket";
    Stack<int> st(str.length());
   

    cout<<"Stack top: "<<st.top()<<endl;

    
    for (int i = 0 ; i < str.length() ; i++){
        st.push(str.at(i));
    }
    string reverse = "";
    for(int i = 0 ; i < str.length() ; i++){
        reverse += st.pop();
    }
    cout<<"Original: "<<str<<endl;
    cout<<"Reversed: "<<reverse<<endl;
    return 0;
}