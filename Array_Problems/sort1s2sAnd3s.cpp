#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec{1,2,0,2,0,2,0,2,0,1,0,2,1,2,1,2};
    int left = 0,mid = 0;
    int right = vec.size() - 2;

    while(mid <= right){
        if(vec[mid] == 0){
            swap(vec[left], vec[mid]);
            left++;
            mid++;
        }
        else if(vec[mid] == 1){
            mid++;
        }
        else{
            swap(vec[mid], vec[right]);
            right--;
        }
    }

cout<<"0s, 1s and 2s sorted array: ";
for(const auto &x: vec){
    cout<<x<<" ";
}
cout<<endl;
return 0;
}