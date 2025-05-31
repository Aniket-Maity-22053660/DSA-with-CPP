#include<iostream>
#include<vector>

using namespace std;

void SubString(vector<char> vec, vector<char> output, int index, vector<vector<char>> &ans){
    if(index >= vec.size()){
        ans.push_back(output);
        return;
    }

    SubString(vec, output, index+1, ans);
    char element = vec.at(index);
    output.push_back(element);
    SubString(vec, output, index+1, ans);
    return;
}

int main(){
    vector<char> vec {'c', 'a', 't'};
    vector<vector<char>> ans;
    vector<char> output;
    int index = 0;
    SubString(vec, output, index, ans);

    vector<vector<char>>:: iterator it1 = ans.begin();
    vector<char>:: iterator it2;
    cout<<'{';
    for(; it1 != ans.end() ; it1++){
        cout<<'{';
        for(it2 = it1->begin() ; it2 != it1->end() ; it2++){
            cout<<*it2;
            if(next(it2) != it1->end()){
                cout<<", ";
            }
        }
        cout<<"}";
        if(next(it1) != ans.end()){
            cout<<", ";
        }
    }
    cout<<'}'<<endl;
    return 0;
}