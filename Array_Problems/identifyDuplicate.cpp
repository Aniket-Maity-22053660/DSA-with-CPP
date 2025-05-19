#include<iostream>

using namespace std;



int main(){

    int arr[] = {1,2,3,4,5,5}; 
    int ans = 0;
    for(int i = 0 ; i < (sizeof(arr)/sizeof(int)) ; i++){
        ans ^= arr[i];
    }
    for(int i = 1 ; i < (sizeof(arr)/sizeof(int)) ; i++){
        ans ^= i;
    }

    cout<<"Duplicate Element: "<<ans<<endl;
    return 0;
}