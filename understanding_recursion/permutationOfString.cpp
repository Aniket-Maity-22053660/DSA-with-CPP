#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(string name, int index, vector<string> &ans){
    if(index >= name.size()){
        ans.push_back(name);
        return;
    }
    for(int j = index ; j < name.size() ; j++){
        swap(name.at(index), name.at(j));
        solve(name, index+1, ans);
        swap(name.at(index), name.at(j));
    }
}
int main(){
    string name = "cat";
    vector<string> ans;
    int index = 0;
    solve(name, index, ans);
    vector<string>::iterator it = ans.begin();

    cout<<'{';
    for(; it != ans.end() ; it++){
        cout<<*it;
        if(next(it) != ans.end()){
            cout<<", ";
        }
        else{
            cout<<'}'<<'\n';
        }
    }

    return 0;
}