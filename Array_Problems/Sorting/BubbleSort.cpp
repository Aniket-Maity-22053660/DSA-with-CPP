#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec{2,1,3,4,5,3,4,5,2,3,4,6,7,8,6,7,94,0};
    int flag;
    for(int i = 0 ; i < vec.size() ; i++){
        flag = 0;
        for(int j = 0 ; j < (vec.size() - 1) - i ; j ++){
            if(vec.at(j) > vec.at(j+1)){
            swap(vec.at(j), vec.at(j+1));
            flag = 1;
            }
        }
        if(flag == 0)
        break;
    }
    cout<<"Bubble Sort: ";
    for(const auto& x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}