#include<iostream>
#include<string>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z')
    return ch;
else{
    return (ch - 'A' + 'a');
}
} 

int main(){
    string name;
    bool ans = true;
    cout<<"Enter the name: ";
    getline(cin, name);

    int start = 0, end = name.length() - 1;

    while(start < end){
        if (!isalnum(name[start])){
            start++;
            continue;
        }
        if(!isalnum(name[end])){
            end--;
            continue;
        }
        if(toLowerCase(name[start]) == toLowerCase(name[end])){
            start++;
            end--;
        }
        else{
            ans = false;
            break;
        }
    }
    if(ans){
        cout<<"Yes, this name is a palindrome!"<<endl;
    }
    else{
        cout<<"This name is not a palindrome!"<<endl;
    }
    return 0;
}