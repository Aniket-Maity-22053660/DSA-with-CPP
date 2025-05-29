#include<iostream>
#include<vector>
using namespace std;

bool isSorted(int *arr, int size){
    if(size <= 1){
        return true;
    }
    else if(arr[0] > arr[1]){
        return false;
    }
    else{
        return isSorted(arr+1, size-1);
    }
}
int main(){
    vector<int> vec {1,2,3,400,5,6,7,87,88};
    bool ans = isSorted(vec.data(), vec.size());
    if(ans){
        cout<<"Yes! the array is sorted in ascending order."<<endl;
    }
    else{
        cout<<"The array is not sorted in ascending order."<<endl;
    }
    return 0;
}