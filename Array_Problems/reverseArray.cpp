#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec{1,2,34,5,6,7,8,9,2};

    int left = 0, right = vec.size()-1;

    while(left < right){
        swap(vec.at(left), vec.at(right));
        left++;
        right--;
    }
    cout<<"Array after reverse: ";
    for(const auto& x: vec){
        cout<<x<<" ";
    }
    return 0;
}