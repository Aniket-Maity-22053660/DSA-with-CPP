#include<iostream>
#include<vector>

using namespace std;

int findSum(int* arr, int size){
    int total = 0;
    if(size == 0){
        return 0;
    }
    total = findSum(arr+1, size-1);
    total = total + arr[0];
    return total;
}

int sumTail(int* arr, int size, int accum = 0){
    if(size == 0){
        return accum;
    }
    return sumTail(arr+1, size-1, arr[0]+accum);
}
 

int main(){
    vector<int> vec {1,2,3,23,43,546,42,78};
    int sum = findSum(vec.data(), vec.size());
    cout<<"Total sum obtained: "<<sum<<endl;
    sum = sumTail(vec.data(), vec.size());
    cout<<"Total sum obtained: "<<sum<<endl;

    return 0;
}