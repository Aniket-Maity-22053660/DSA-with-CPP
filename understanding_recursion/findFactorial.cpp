#include<iostream>

using namespace std;

int fact(int num){
    if(num == 0){
        return 1;
    }

    return num*fact(num-1);
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    int ans = fact(num);
    cout<<"Factorial of "<<num<<" : "<<ans<<endl;
    return 0;
}