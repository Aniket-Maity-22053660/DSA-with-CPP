#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<stack>

using namespace std;
template <class T>
class Stack{
    int size;
    T *arr;
    int topIndex;
    public:
    Stack(T size){
        this->size = size;
        arr = new T[size];
        topIndex = -1;
    };
    void push(T data);
    T pop();
    T top();
};

template<class T>
void Stack<T>:: push(T data){
    if(topIndex < size-1){
        topIndex++;
        arr[topIndex] = data;
    }else{
        cout<<"Stack overflow!"<<endl;
    }
}

template<class T>
T Stack<T>:: pop(){
    if(topIndex >= 0){
        cout<<arr[topIndex]<<endl;
        T value = arr[topIndex];
        topIndex--;  
        return value; 
    }else{
        cout<<"Stack underflow!"<<endl;
        return T();
    }
}

template<class T>
T Stack<T>:: top(){
    if(topIndex >= 0){
        cout<<arr[topIndex]<<endl;
        return arr[topIndex];
    }else{
        cout<<"Stack underflow!"<<endl;
        return T();
    }
}

#endif