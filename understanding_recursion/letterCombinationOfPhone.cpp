#include<iostream>
#include<vector>

using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, vector<string> mapping){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }
    int number = digits.at(index) - '0';
    string value = mapping[number];

    for(int i = 0 ; i < value.length() ; i++){
        output.push_back(value.at(i));
        solve(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
}
int main(){
    vector<string> mapping {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string output;
    int index = 0;
    string digits = "";
    solve(digits, output, index, ans, mapping);
    vector<string>:: iterator it = ans.begin();
    if(!ans.empty())
    cout<<'{';
    for(;it != ans.end() ; it++){
        cout<<*it<<" ";
        if(it+1 != ans.end()){
            cout<<", ";
        }
        else{
            cout<<'}';
        }
    }
    cout<<'\n';
    return 0;
}