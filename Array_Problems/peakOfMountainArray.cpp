#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq {1,2,3,4,5,6, 7,8, 9,  6, 4, 2};
    int left = 0, right = dq.size() - 1;

    while(left < right){
        int mid = left + (right - left)/2;
        if(dq[mid] < dq[mid+1]){
            left = mid+1;
        }
        else{
            right = mid;
        }
        
    }
    cout<<"Peak of the array: "<<dq[right]<<endl;




    return 0;
}