#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> arr= {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int top = 0, left = 0, right = arr[0].size() - 1, bottom = arr.size()-1;
    vector<int> ans;

    while(top <= bottom && left <= right){
        for(int i = left ; i <= right ; i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i = top ; i <= bottom ; i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i = right ; i >= left ; i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left <= right){
            for(int i = bottom ; i >= top ; i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    for(const auto& x: ans){
        cout<<x<<" ";
    }
    cout<<'\n';
    return 0;
}