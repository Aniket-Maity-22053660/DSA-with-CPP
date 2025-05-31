#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void subSet(vector<int> vec, vector<int> output, int index, vector<vector<int>> &ans){
    if(index >= vec.size()){
        if(ans.size() == 0){
            cout<<'{';
        }
        int cnt = 1;
        ans.push_back(output);
        cout<<'{';
        for(const auto &x: output){
            cout<<x;
            if(cnt++ < output.size()){
                cout<<", ";
            }
        }
        cout<<'}';
        if(ans.size() < pow(2, vec.size())){
            cout<<", ";
        }
        else{
            cout<<'}';
        }
        return;
    }

    subSet(vec, output, index+1, ans);
    int element = vec.at(index);
    output.push_back(element);
    subSet(vec, output, index+1, ans);
}
int main(){
    vector<int> vec {1, 2, 3};
    vector<int> output;
    vector<vector<int>> ans;
    int index = 0;
    subSet(vec, output, index, ans);
    cout<<'\n';
    return 0;
}