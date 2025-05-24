#include<iostream>
#include<string>

using namespace std;

int main(){
    string str = "daabcbaabcbc";
    string part = "abc";

    while(str.length() != 0 && str.find(part) < str.length()){
        str.erase(str.find(part), part.length());
    }
    cout<<"After removing all occurrences of "<<part<<" : "<<str<<endl;
    return 0;
}