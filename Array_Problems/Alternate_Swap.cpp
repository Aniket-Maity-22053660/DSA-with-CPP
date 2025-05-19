#include<iostream>
#include<vector>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of your array: ";
    cin>>size;

    vector<int> vec(size);

    for(int &x: vec){
        cout<<"Enter the array element: ";
        cin>>x;
    }
    vector<int>:: iterator it;
    cout<<"Array before alternate swap: ";
    for(int &x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    for(it = vec.begin(); it != vec.end() ; it = it+2){
        if(it != vec.end()-1){
            int temp = *it;
            *it = *(it+1);
            *(it+1) = temp;
        }
        else{
            break;
        }
    }
    
    cout<<"Array after alternate swap: ";
    for(int &x: vec){
        cout<<x<<" ";
    }

    return 0;
}