#include<iostream>

using namespace std;

int fib(int num){
    if(num == 0){
        //cout<<num<<" ";
        return num;
    }
    if(num == 1){
        //cout<<num<<" ";
        return num;
    }
    return fib(num-1)+fib(num-2);
}

void printFib(int num){
    if(num == 0){
        int a = 0;
        cout<<a<<" ";
    }else if(num > 0){
        int a = 0;
        int b = 1;
        cout<<a<<" ";
        cout<<b<<" ";
        for(int i = 2 ; i <= num ; i++){
            int c = a + b;
            cout<<c<<" ";
            a = b;
            b = c;
        }
        cout<<'\n';
    }
    else{
        cout<<"Invalid number!"<<endl;
    }
}

void findFib(int num){
    int i = 0;
    while(i <= num){
        int ans = fib(i);
        cout<<ans<<" ";
        i++;
    }
    cout<<'\n';
}

int main(){
    int num;
    cout<<"Enter the nth term: ";
    cin>>num;

    findFib(num);
    printFib(num);
    return 0;
}