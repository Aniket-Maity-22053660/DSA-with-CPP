#include<iostream>

using namespace std;

int main(){
    int number, ans = 0, flag = 0;
    cout<<"Enter the number you want to reverse: ";
    cin>>number;
    
    while(number != 0){
        int digit = number%10;
        if(ans < INT_MAX/10){
        ans = ans*10 + digit;
        number /= 10;
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag != 1){
    cout<<"Your number after reversal: "<<ans<<endl;
    }
    else{
        cout<<"Number is greater than range!!";
    }
    return 0;
}