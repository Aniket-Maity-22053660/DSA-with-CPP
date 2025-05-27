#include<iostream>
 
using namespace std;

int gcd(int num1, int num2){
    if(num1 == 0){
        return num2;
    }
    if(num2 == 0){
        return num1;
    }

    while(num1 != num2){
        if(num1 > num2){
            num1 = num1 - num2;
        }
        else{
            num2 = num2 - num1;
        }
    }
    return num1;
}

int main()
{
    int num1, num2;
    cout<<"Enter two numbers to find GCD: ";
    cin>>num1>>num2;
    cout<<"GCD of "<<num1<<" and "<<num2<<" is "<<gcd(num1, num2)<<endl;
    return 0;
}

