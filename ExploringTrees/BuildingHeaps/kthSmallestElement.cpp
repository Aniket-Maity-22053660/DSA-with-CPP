#include<iostream>
#include<vector>

using namespace std;

void swap(int i1, int i2, vector<int> &vec){
    int temp = vec.at(i1);
    vec.at(i1) = vec.at(i2);
    vec.at(i2) = temp;
}

void heapify(vector<int> &vec, int i){
    int smallest = i;
    int left = 2*smallest;
    int right = 2*smallest + 1;

    if(left < vec.size() && vec.at(left) < vec.at(smallest)){
        smallest = left;
    }
    if(right < vec.size() && vec.at(right) < vec.at(smallest)){
        smallest = right;
    }
    if(smallest != i){
        swap(smallest, i, vec);
        heapify(vec, smallest);
    }
}
void make_heap(vector<int> &vec){
    for(int i = vec.size() / 2 ; i >= 1 ; i--){
        heapify(vec, i);
    }
}

int main(){
    int size, element;
    vector<int>:: iterator it;
    cout<<"Enter the number of elements: ";
    cin>>size;
    vector<int> vec(size + 1);
    for(int i = 1 ; i < vec.size() ; i++){
        cout<<"Enter the element"<<(i)<<": ";
        cin>>element;
        vec.at(i) = element;
    }
    cout<<"Given elements: ";
    for(it = vec.begin() + 1 ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<'\n';
    int K;
    cout<<"Finding the Kth smallest element:- "<<endl;
    cout<<"Enter the value of K: ";
    cin>>K;
    make_heap(vec);
    int ans;
    while(K > 0){
        swap(1, vec.size() - 1, vec);
        ans = vec.back();
        vec.pop_back();
        heapify(vec, 1);
        K--;
    }
    cout<<"Kth smallest element: "<<ans<<endl;
}