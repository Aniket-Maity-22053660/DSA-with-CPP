#include<iostream>
#include<vector>
#define Row 3
#define Col 3
using namespace std;

int main(){
    int arr[Row][Col] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> vec;
    int target = 8, flag = 0;
    for(int i = 0 ; i < Row ; i++){
         vector<int> row;
        for(int j = 0 ; j < Col ; j++){
           row.push_back(arr[i][j]);
        }
         vec.push_back(row);
    }

    for(const vector<int> &x: vec){
        for(int num: x){
            cout<<num<<" ";
        }
        cout<<'\n';
    }

    int start = 0, end = Row*Col - 1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if(vec.at(mid/Col).at(mid%Col) == target){
            cout<<"Target: "<<target<<" found at row: "<<mid/Col<<" col: "<<mid%Col<<endl;
            flag = 1;
            break;
        }
        else if(vec.at(mid/Col).at(mid%Col) < target){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
    }
    if(flag != 1){
        cout<<"Target element was not found in the array!"<<endl;
    }
    return 0;
}