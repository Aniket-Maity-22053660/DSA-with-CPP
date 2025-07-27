#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Heaps{
    vector<int> Arr {INT_MAX};
    int size = 0;
    void swap(int parent, int index){
         int temp = Arr[parent];
         Arr[parent] = Arr[index];
         Arr[index] = temp;
    }
    public:
    void insert(int data){
        size = size + 1;
        Arr.push_back(data);
        int index = size;
        while(index > 1){
            int parent = index / 2;
            if(Arr[parent] < Arr[index]){
                swap(parent, index);
                index = parent;
            }else{
                return;
            }
        }
    }
    void print(){
        vector<int>::iterator it;
        for(int i = 1 ; i <= size ; i++){
            cout<<Arr[i]<<" ";
        }
        cout<<'\n';
    }

    void heapify(vector<int> &Arr, int index){
        int largest = index;
        int left = 2*largest;
        int right = 2*largest + 1;
        if(left < Arr.size() && Arr[largest] < Arr[left]){
            largest = left;
        }
        if(right < Arr.size() && Arr[largest] < Arr[right]){
            largest = right;
        }
        if(largest != index){
            swap(largest, index);
        }
    }
    void deleteElement(int data){
        int index = -1;
        for(int i = 1 ; i <= size ; i++){
            if(Arr[i] == data){
                index = i;
                break;
            }
        }
        if(index == -1){
            return;
        }
        swap(index, size);
        size = size -1;
        heapify(Arr, index);
    }
};

int main(){
    int size, element;
    cout<<"Enter the elements to be entered in the heap: ";
    cin>>size;
    Heaps* objHeap = new Heaps();
    for(int i = 0 ; i < size ; i++){
        cout<<"Element"<<(i+1)<<": ";
        cin>>element;
        objHeap->insert(element);
    }
    objHeap->print();
    cout<<'\n';
    cout<<"Enter the element you want to delete: ";
    cin>>element;
    objHeap->deleteElement(element);
    cout<<"After deleting an element: ";
    
    objHeap->print();
    cout<<'\n';
    return 0;
}