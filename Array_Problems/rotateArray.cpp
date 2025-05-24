#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec{1, 2, 3, 4, 5, 6};
    int init = 0, pivot = 2;
    while(pivot < vec.size()){
        swap(vec.at(init), vec.at(pivot));
        init++;
        pivot++;
    }
    cout<<"Array after rotation as a pivot index "<<2<<": ";
    for(const auto&x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}