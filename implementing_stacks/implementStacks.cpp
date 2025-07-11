#include<iostream>
#include<stack>

using namespace std;

class Stack{
    int size;
    int *arr;
    int topIndex;
    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        topIndex = -1;
    };
    void push(int data){
        if(topIndex < size-1){
            topIndex++;
            arr[topIndex] = data;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    int pop(){
        if(topIndex >= 0 ){
            cout<<arr[topIndex]<<endl;
            topIndex--;
            if(topIndex == -1){
                delete arr;
            }
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }
    void top(){
        if (topIndex != -1){
            cout<<"Stack top: "<<arr[topIndex]<<endl;
        }
        else{
            cout<<"Stack underflow!"<<endl;
        }
    }
}
int main()
{
    stack<int> st;
    st.push(2);
    st.push(5);
    cout<<st.top()<<endl;
    return 0;
}