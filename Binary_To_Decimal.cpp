#include<iostream>
#include<math.h>

using namespace std;

int main(){
 
    long long bin;
    cout<<"Enter your binary number: ";
    cin>>bin;
    long long  i = 0;
    long long ans = 0;

    while(bin != 0){
        int digit = bin%10;
        if(digit == 1){
            ans += pow(2, i);
        }
        bin = bin/10;
        i++;
    }

    cout<<"Decimal equivalent: "<<ans<<endl;

    return 0;
}