#include<iostream>

using namespace std;

int main(){

    string number;
    cout<<"Enter the binary pattern: ";
    cin>>number;
    for(int i = number.size()-1 ; i>=0 ; i--){
        if(number[i] == '1'){
            number[i] = 0;
        }
        else{
            number[i] = 1;
        }
    }
    cout<<"Your number after 1's complement: "<<number<<endl;
    return 0;
}