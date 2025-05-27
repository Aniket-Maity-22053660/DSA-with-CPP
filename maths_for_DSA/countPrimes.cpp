#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long num;
    cout<<"Enter the number: ";
    cin>>num;
    vector<bool> vec(num, true);
    vec[0] = false, vec[1] = false;
    long long count = 0;
    for(long long i = 0 ; i < num ; i++){
        if(vec[i]){
            count++;
        
            for(long long j = 2*i ; j < num ; j = j+i){ 
                vec[j] = false;
            }
        }
    }

    cout<<"Total no of prime numbers before "<<num<<" is "<<count<<"."<<endl;
    
    return 0;
}