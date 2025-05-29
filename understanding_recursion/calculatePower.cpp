#include<iostream>

using namespace std;

int calculatePow(int base, int expo){
    if(expo == 0){
        return 1;
    }
    else{
        return base * calculatePow(base, expo - 1);
    }
}
int main(){
    int base, expo;
    cout<<"Enter the base: ";
    cin>>base;
    cout<<"Enter the expo: ";
    cin>>expo;
    int ans = calculatePow(base, expo);
    cout<<base<<"^"<<expo<<" = "<<ans<<endl;
    cout<<'\n';
    return 0;
}