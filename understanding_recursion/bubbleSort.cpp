#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> bubbleSort(vector<int> vec, int l, int r){
    if(l > r)
    {
        return vec;
    }
    else{
        for(int i = 0 ; i < r ; i++){
            if(vec.at(i) > vec.at(i+1)){
                swap(vec.at(i), vec.at(i+1));
            }
        }
        return bubbleSort(vec, 0, r-1);
    }
}
int main(){
    vector<int> vec {1,2,1,4,2,5,6,3,6,8,4,2,9,4};

    vector<int> sorted = bubbleSort(vec, 0, vec.size()-1);
    vector<int>:: iterator it = sorted.begin();

    for(; it != sorted.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<'\n';
    return 0;
}