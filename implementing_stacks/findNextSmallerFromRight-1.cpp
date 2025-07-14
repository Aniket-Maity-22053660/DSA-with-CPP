#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<int> vec = {3,5,7,3,9,1};
    vector<int> ans;
    for(int i = 0 ; i < vec.size() ; i++){
        int flag = 1;
        for(int j = i+1 ; j < vec.size() ; j++){
            if(vec[j] < vec[i]){
                ans.push_back(vec[j]);
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            ans.push_back(-1);
        }
    }
    cout<<"Actual array: ";
    vector<int>:: iterator it;
    for(it = vec.begin() ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl<<"Array of next smaller elements from right: ";
    for(it = ans.begin() ; it != ans.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}