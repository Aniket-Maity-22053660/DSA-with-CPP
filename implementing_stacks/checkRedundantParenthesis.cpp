#include<iostream>
#include<stack>
#include "Stack.h"

bool checkRedundant(string str, stack<char> &st){
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            st.push(str[i]);
        }else{
            if(str[i] == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                st.pop();
                if(isRedundant){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    stack<char> st;
    string str;
    cout<<"Enter the mathematical expression: ";
    cin>>str;
    if(checkRedundant(str, st)){
        cout<<"Redundant parenthesis is present!"<<endl;
    }else{
        cout<<"There is no redundant parenthesis!"<<endl;
    }
    return 0;
}