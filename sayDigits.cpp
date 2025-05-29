#include<iostream>
#include<list>
using namespace std;

int main(){
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    list<string> li;
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    while(num != 0){
        int digit = num%10;
        li.push_front(arr[digit]);
        num /= 10;
    }
    list<string>:: iterator it = li.begin();
    for(;it != li.end() ; it++){
        cout<<*it;
        if(next(it) != li.end()){
            cout<<" ";
        }
    }
    cout<<'\n';
    return 0;
}