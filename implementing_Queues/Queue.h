#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

using namespace std;

template<class T>
class Queue{
    T*arr;
    int front, rear;
    public:
    int size;
    Queue(int size){
        this->size = size;
        arr = new T[size];
        front = -1;
        rear = -1;
    }
    void push(T element);
    T pop();
    bool isEmpty();
    T Front();
    T Rear();
    ~Queue(){
        delete [] arr;
    }
};

template<class T>
void Queue<T>::push(T element){
    if(rear < size - 1){
        rear += 1;
        if(front == -1){
            front += 1;
        }
        arr[rear] = element;
    }else{
        cout<<"Queue overflow!"<<endl;
    }
}

template<class T>
T Queue<T>::pop(){
    if((front != -1 && rear != -1) && front <= rear){
        T element = arr[front];
        front += 1;
        if(front > rear){
            front = -1;
            rear = -1;
        }
        return element;
    }else{
        cout<<"Queue underflow!"<<endl;
        return T();
    }
}

template<class T>
bool Queue<T>::isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }else{
        return false;
    }
}

template<class T>
T Queue<T>::Front(){
    if(front != -1){
        return arr[front];
    }else{
        cout<<"Queue is empty!"<<endl;
        return T();
    }
}

template<class T>
T Queue<T>::Rear(){
    if(rear != -1){
        return arr[rear];
    }else{
        cout<<"Queue is empty!"<<endl;
        return T();
    }
}

#endif
