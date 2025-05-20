#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec {0,1,1,1,1,1,0,0,1,0,1,0,1,1};

    int right = vec.size()-1;
    int left = 0;
    while(left < right){
        if(vec.at(left) == 1 && vec.at(right) ==0){
            swap(vec[left], vec[right]);
            left++;
            right--;
        }else{
            if(vec.at(left) == 0)
            left++;
            if(vec.at(right) == 1)
            right--;
        }
    }


    for(const auto &x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}