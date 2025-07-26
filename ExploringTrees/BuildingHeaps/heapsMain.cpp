#include<iostream>
#include<vector>

using namespace std;

class Heaps{
    vector<int> arr(1, INT_MAX);
    int size = 0;
    void swap(int parent, int index){
         int temp = arr[parent];
         arr[parent] = arr[index];
         arr[index] = temp;
    }
    public:
    void insert(int data){
        size = size + 1;
        arr.push_back(data);
        int index = size;
        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(parent, index);
                index = parent;
            }else{
                return;
            }
        }
    }
    void print(){
        vector<int>::iterator it;
        for(it = arr.begin() + 1 ; it != arr.end() ; it++){
            cout<<*it<<" ";
        }
        cout<<'\n';
    }
};