#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> vec {1,2,3,4,5,5,5,5,4,4,4,3,3,7,8,7,7,7,6,4,4,3,1,1,2};
    sort(vec.begin(), vec.end());
    for(const auto &x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    int left = 0 , right =vec.size()-1, low, high;
    int target = 4;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(vec.at(mid) < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    low = left;
    left = 0; right = vec.size() - 1;
    while(left <= right){
        int mid = left+ (right - left)/2;
        if(vec.at(mid) > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    high = right;
    cout<<"Left most position: "<<low<<endl;
    cout<<"Right most position: "<<high<<endl;
    cout<<"Total no. of occurrences: "<<(high - low)+1<<endl;
    return 0;
}