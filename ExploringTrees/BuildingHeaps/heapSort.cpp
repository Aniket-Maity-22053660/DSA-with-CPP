#include<iostream>
#include<vector>

using namespace std;

void swap(int i1, int i2, vector<int> &vec){
    int temp = vec[i1];
    vec[i1] = vec[i2];
    vec[i2] = temp;
}
void heapify(vector<int> & vec, int i){
    int largest = i;
    int left = 2*largest;
    int right = 2*largest + 1;
    if(left < vec.size() && vec[left] > vec[largest]){
        largest = left;
    } 
    if(right < vec.size() && vec[right] > vec[largest]){
        largest = right;
    }
    if(largest != i){
        swap(largest, i, vec);
        heapify(vec, largest);
    }
}
void make_heap(vector<int> &vec){
    for(int i = vec.size() / 2 ; i >= 1 ; i--){
        heapify(vec, i);
    }
}

vector<int> heap_sort(vector<int> &vec, vector<int> &ans){
    int size = ans.size() - 1;
    int element;
    while(vec.size() > 2){
        swap(1, vec.size() - 1, vec);
        element = vec.back();
        vec.pop_back();
        heapify(vec, 1);
        ans[size--] = element;
    }
    ans[size] = vec[1];
    return ans;
}

int main(){
    int size, element;
    vector<int>::iterator it;
    cout<<"Enter the number of elements to be sorted(Heap Sort):";
    cin>>size;
    vector<int> vec(size + 1);
    vector<int> ans(size);
    for(int i = 1 ; i < vec.size() ; i++){
        cout<<"Enter the element"<<i<<": ";
        cin>>element;
        vec[i] = element;
    }
    cout<<"Before sorting: ";
    for(it = vec.begin()+1 ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<'\n';
    make_heap(vec);
    ans = heap_sort(vec, ans);
    cout<<"After sorting: ";
    for(it = ans.begin() ; it != ans.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<'\n';
    return 0;
}