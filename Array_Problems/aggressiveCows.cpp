#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> vec, int mid, int cows){
    int cowCount = 1, lastPos = vec[0];

    for(const auto &x: vec){
        if(x-lastPos >= mid){
            cowCount++;
            if(cowCount == cows){
                return true;
            }
            lastPos = x;
        }
    }
    return false;
}
int main(){
    vector<int> vec {4, 2, 1, 3, 6};
    sort(vec.begin(), vec.end());
    vector<int>:: iterator it = max_element(vec.begin(), vec.end());
    int start = 0, end = *it, cows = 3, ans = -1;

    while(start <= end){
        int mid =  start + (end - start)/2;
        if(isPossible(vec, mid, cows)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout<<"The minimum distance between any two cows which is as large as possible: "<<ans<<endl;
    
    return 0;
}
