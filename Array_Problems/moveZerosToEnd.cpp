#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> fun1(vector<int> vec){
    vector<int>:: iterator zeroPtr = vec.end()-1;
    vector<int>:: iterator nonZeroPtr = vec.begin();
    while(nonZeroPtr <= zeroPtr){
        if(*nonZeroPtr == 0){
            swap(*nonZeroPtr, *zeroPtr);
            zeroPtr--;
        }
        else{
            nonZeroPtr++;
        }
    }
    return vec;
}

int main(){
    vector<int> vec{1, 0, 2, 0, 3, 0};
    for(const auto& x: fun1(vec)){
        cout<<x<<" ";
     }
     cout<<endl;
    vector<int>:: iterator it1 = vec.begin();
    vector<int>:: iterator it2;
    for(it2 = vec.begin() ; it2 != vec.end() ; it2++){
        if(*it2 != 0){
            swap(*it1, *it2);
            it1++;
        }
    }
    
    cout<<"After moving all zeros to the right: ";
    for(const auto& x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
     
    return 0;
}