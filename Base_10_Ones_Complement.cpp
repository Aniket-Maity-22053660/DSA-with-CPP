#include<iostream>

using namespace std;

int main(){
    int number;
    cout<<"Provide the number: ";
    cin>>number;
    int mask = 0, m = number, flag = 0;
    if(m == 0 ){
        flag = 1;
    }
    while(m != 0 ){
        mask = mask<<1|1;
        m = m>>1;
    }
    int ans = (~number)&mask;
    if(flag != 1){
    cout<<"One's complement(base-10): "<<ans<<endl;
    }
    else{
        cout<<"One's complement(base-10): "<<0<<endl;
    }

    return 0;
}