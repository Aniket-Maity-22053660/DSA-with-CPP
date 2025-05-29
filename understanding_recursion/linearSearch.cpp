#include<iostream>
#include<vector>
using namespace std;

int linSearch(int *arr, int size, int ele){
    if(arr[0] == ele){
        return size;
    }
    else if(size == 0){
        return -1;
    }
    return linSearch(arr+1, size-1, ele);
}
int main(){
    vector<int> vec {1,2,43,36,76,45,98};
    int element = 2;
    int found = linSearch(vec.data(), vec.size(), element);
    cout<<"Element "<<element<<" was found at index: "<<(vec.size() - found)<<endl;

    return 0;
}