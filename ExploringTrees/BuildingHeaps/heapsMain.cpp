#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Heaps{
    vector<int> Arr {INT_MAX};
    int size = 0;
    void swap(int parent, int index, vector<int> &vec){
         int temp = vec[parent];
         vec[parent] = vec[index];
         vec[index] = temp;
    }
    public:
    void insert(int data){
        size = size + 1;
        Arr.push_back(data);
        int index = size;
        while(index > 1){
            int parent = index / 2;
            if(Arr[parent] < Arr[index]){
                swap(parent, index, Arr);
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
            swap(largest, index, Arr);
            heapify(Arr, largest);
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
        swap(index, size, Arr);
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
    cout<<"Heapify a given vector:-"<<endl;
    cout<<"Enter the size of the vector: ";
    vector<int> vec1(1, INT_MAX);
    int size1;
    cin>>size1;
    for(int i = 1 ; i <= size1 ; i++){
        cout<<"Element"<<(i-1)<<": ";
        cin>>element;
        vec1.push_back(element);
    }
    for(int i = (vec1.size() / 2) ; i >= 1 ; i--){
        objHeap->heapify(vec1, i);
    }
    cout<<"After heapify the elements would be: ";
    for(int i= 1 ; i < vec1.size() ; i++){
        cout<<vec1.at(i)<<" ";
    }
    cout<<'\n';
    return 0;
}