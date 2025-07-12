#include<iostream>
#include "Stack.h"
using namespace std;

bool Check(string str){
    Stack<char> st(str.length());
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '[' || str[i] == '{' || str[i] == '('){
            st.push(str[i]);
        }else if(str[i] == ']' || str[i] == '}' || str[i] == ')'){
            if(st.isEmpty()){
                return false;
            }
            char popped = st.pop();
            if(popped =='[' && str[i] == ']' || popped == '{' && str[i] == '}' || popped == '(' || str[i] == ')'){
                continue;
            }else{
                return false;
            }
        }
    }
    if(st.isEmpty()){
        return true;
    }
    return false;
}
int main(){
    string str;
    cout<<"Enter the mathematical expression: ";
    cin>>str;
    cout<<"Matched: "<<(Check(str)?"Ah yes!":"sorry!")<<endl;
    return 0;
}