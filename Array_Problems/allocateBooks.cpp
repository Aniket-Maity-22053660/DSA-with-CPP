#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int mid, int n, int m){
    int pageSum = 0, studentCnt = 1 ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] + pageSum <= mid){
            pageSum += arr[i];
        }
        else{
            studentCnt++;
            pageSum = arr[i];
            if(studentCnt > m || arr[i] > mid){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> vec {12, 34, 67, 90};
    int sum = 0, start = 0, end, n=4, m=2;

    for(const auto &x: vec){
        sum +=x;
    }
    end = sum;
    int ans = -1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if(isPossible(vec, mid, n, m)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid  + 1;
        }
    }
    cout<<"Maximum number of books that can be alocated to a student which is minimum is "<<ans<<endl;
    return 0;
}