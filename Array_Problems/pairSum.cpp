#include <iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(){
    vector<int> vec = {1,2,2,3,4,4,5,8};
    int sum = 9;
    set<vector<int>> ans;
    for(int i = 0 ; i < vec.size() ; i++){
        for(int j = i+1 ; j < vec.size() ; j++){
            if(vec[i]+vec[j] == sum){
                vector<int> temp;
                temp.push_back(min(vec[i], vec[j]));
                temp.push_back(max(vec[i], vec[j]));
                ans.insert(temp);
            }
        }
    }

    cout << "Pair Sum: ";
    for(const auto &x: ans){
        cout<<"("<<x[0]<<", "<<x[1]<<")"<<" ";
    }
    return 0;
}