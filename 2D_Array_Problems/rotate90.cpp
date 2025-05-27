#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> ans(arr[0].size(), vector<int>(arr.size()));
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0 ; j < arr[0].size() ; j++){
            ans[(arr[0].size()-1)-j][i] = arr[i][j];
        }
    }
    
    vector<vector<int>>:: const_iterator rowIt = ans.cbegin();
    vector<int>:: const_iterator colIt;
    
    for(; rowIt != ans.cend() ; rowIt++){
        for(colIt = rowIt->cbegin(); colIt != rowIt->cend() ; colIt++){
            cout<<*colIt<<" ";
        }
        cout<<endl;
    }
    return 0;
}