#include<iostream>

using namespace std;

int main(){

    int arr[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    for(int i = 0 ; i < 4; i++){
        for(int j = 0 ; j < (sizeof(arr)/sizeof(int))/4  ; j++){
            if(i%2 != 0 ){
                cout<<arr[2-j][i]<<" ";
            }
            else{
                cout<<arr[j][i]<<" ";
            }
        }
    }
    for (int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < (sizeof(arr)/sizeof(int)/4) ; j++){
            if(i%2 != 0){
                cout<<arr[j][i]<<" ";
            }else{
                cout<<arr[(sizeof(arr)/sizeof(int))/4 - 1 - j][i]<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}