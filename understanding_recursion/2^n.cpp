#include<iostream>

using namespace std;

int findPow(int pow){
    if(pow == 0){
        return 1;
    }
    else {
        return 2*findPow(pow-1);
    }
}

int main(){
    int pow;
    cout<<"Enter the power: ";
    cin>>pow;

    int ans = findPow(pow);
    cout<<"2^"<<pow<<" : "<<ans<<endl;
    return 0;
}