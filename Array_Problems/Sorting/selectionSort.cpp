#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec{1,2,3,2,1,23,4,5,4,3,5,4,8,7};
    for(int  i = 0 ; i < vec.size()-1 ; i++){
        int minIndex = i;
        for(int j= i+1 ; j <vec.size() ; j++)
        if(vec.at(j) < vec.at(minIndex))
        minIndex = j;
    swap(vec.at(minIndex), vec.at(i));
    }
    cout<<"Selection sort: ";
    for(const auto& x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}