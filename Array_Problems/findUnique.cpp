#include<iostream>
#include<deque>
using namespace std;

int main(){
    
    int arr[] = {2,3,2,4,5,4,5,7,3};
    deque<int> dq(arr, arr+(sizeof(arr) / sizeof(arr[0])));
    deque<int>:: iterator it;
    int ans = 0;
    for(it = dq.begin() ; it != dq.end() ; it++){
        ans ^=  *it;
    }

    cout<<"Your array: ";
    for(auto &x: arr){
        cout<<x<<" ";
    }
    cout<<endl<<"Unique element in the array: "<<ans<<endl;



    return 0;
}