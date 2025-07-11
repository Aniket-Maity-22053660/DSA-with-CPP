#include<iostream>

using namespace std;

class TwoWayStack{
    int size;
    int *arr;
    int left, right;
    public: 
    TwoWayStack(int size){
        this->size = size;
        arr = new int[size];
        left = -1;
        right = size;
    }
    void pushLeft(int data){
        if(left < right-1){
            left = left + 1;
            arr[left] = data;
        }
        else{
            cout<<"Stack overflow from left!"<<endl;
        }
    }
    void pushRight(int data){
        if(right > left+1){
            right = right -1;
            arr[right] = data;
        }
        else{
            cout<<"Stack overflow from right!"<<endl;
        }
    }
    void popLeft(){
        if(left >= 0){
            left--;
        }
        else{
            cout<<"Stack underflow from left!"<<endl;
        }
    }
    void popRight(){
        if(right < size){
            right++;
        }else{
            cout<<"Stack underflow from right!"<<endl;
        }
    }
    void topLeft(){
        if(left >= 0){
            cout<<arr[left]<<endl;
        }else{
            cout<<"Stack underflow from left!"<<endl;
        }
    }
    void topRight(){
        if(right < size){
            cout<<arr[right]<<endl;
        }
        else{
            cout<<"Stack underflow from right!"<<endl;
        }
    }
    ~TwoWayStack(){
        delete [] arr;
    }
};
int main(){

    return 0;
}