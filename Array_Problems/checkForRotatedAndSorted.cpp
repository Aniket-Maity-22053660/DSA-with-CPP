#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vec{3, 4, 5, 1, 0, 2};
    int sorted = 0, rotated = 0;
    for(int i = 0 ; i < vec.size()-1 ; i++){
        if(vec.at(i) > vec.at(i+1)){
            sorted++;
        }
    }
    if(vec.at(vec.size()-1) > vec.at(0)){
        rotated++;
    }
    if(sorted <= 1 && rotated == 0){
       cout<<"The array is 100% sorted and rotated!"<<endl;
    }
    else if(sorted > 1 && rotated == 0){
        cout<<"The array is not sorted!"<<endl;
    }
    else if(rotated > 0 && sorted <= 1){
        cout<<"The array is not rotated!"<<endl;
    }
    return 0;
}