#include<iostream>
#include<vector>
#include<utility>
using namespace std;

bool isValid(pair<int, int> start, vector<vector<int>> &map, vector<vector<int>> &mat, int N = 4){
    int i = start.first;
    int j = start.second;
    
    // First, check bounds
    if(i >= 0 && j >= 0 && i < N && j < N &&
       map[i][j] != 0 && mat[i][j] != 1){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &map, pair<int, int> start, pair<int, int> goal, string output, vector<string> &ans, vector<vector<int>> &mat){
    if(start.first == goal.first && start.second == goal.second){
        ans.push_back(output);
        return;
    }
    if(map[start.first][start.second] == 0){
        ans.push_back(output);
        return;
    }
    mat[start.first][start.second] = 1;

    if(isValid({start.first+1, start.second}, map, mat)){
        output.push_back('D');
        solve(map, {start.first+1, start.second}, goal, output, ans, mat);
        output.pop_back();
    }
    if(isValid({start.first, start.second-1}, map ,mat)){
        output.push_back('L');
        solve(map, {start.first, start.second-1}, goal, output, ans, mat);
        output.pop_back();
    }
    if(isValid({start.first, start.second+1}, map, mat)){
        output.push_back('R');
        solve(map, {start.first, start.second+1}, goal, output, ans, mat);
        output.pop_back();
    }
    if(isValid({start.first-1, start.second}, map, mat)){
        output.push_back('U');
        solve(map, {start.first-1, start.second}, goal, output, ans, mat);
        output.pop_back();
    }
    mat[start.first][start.second] = 0;
    return;
}

int main(){
    vector<vector<int>> map = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> mat(4, vector<int> (4, 0));
    string output = "";
    vector<string> ans;
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {3, 3};

    solve(map, start, goal, output, ans, mat);

    vector<string>:: iterator it = ans.begin();
    
    cout<<'{';
    for(; it != ans.end() ; it++){
        cout<<*it;
        if(next(it) != ans.end()){
            cout<<", ";
        }
        else{
            cout<<'}';
        }
    }
    cout<<'\n';
    return 0;
}