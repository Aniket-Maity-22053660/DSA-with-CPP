#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int num;
    cout<<"Enter your number: ";
    cin>>num;
    bool ans = false;
    int keep = 1;

    for(int i = 0 ; i<= 30 ; i++){
       keep = pow(2, i);
       if(keep == num){
        ans = true;
        break;
       }
    }
    if(ans){
        cout<<"Yes! the number is a power of TWO."<<endl;
    }
    else{
        cout<<"The number is not a power of TWO."<<endl;
    }
    return 0;
}