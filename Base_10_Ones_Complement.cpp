#include<iostream>

using namespace std;

int main(){
    int number;
    cout<<"Provide the number: ";
    cin>>number;
    int mask = 0, m = number;

    while(m != 0 ){
        mask = mask<<1|1;
        m = m>>1;
    }
    int ans = (~number)&mask;
    cout<<"One's complement(base-10): "<<ans<<endl;

    return 0;
}