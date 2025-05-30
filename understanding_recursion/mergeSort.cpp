#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &vec, int l, int r){
    int mid = l + (r-l)/2;
    int n1 = mid - l + 1, n2 = r-mid;
    int *L1 = new int[n1];
    int *L2 = new int[n2];
    int mainIndex = l;
    for(int i = 0 ; i < n1 ; i++){
        L1[i] = vec.at(mainIndex++);
    }
    for(int i = 0 ; i < n2 ; i++){
        L2[i] = vec.at(mainIndex++);
    }
    mainIndex = l;
    int index1 = 0, index2 = 0;

    while(index1 < n1 && index2 < n2){
        if(L1[index1] < L2[index2]){
            vec[mainIndex++] = L1[index1++];
        }
        else{
            vec[mainIndex++] = L2[index2++];
        }
    }

    while(index1 < n1){
        vec[mainIndex++] = L1[index1++];
    }
    while(index2 < n2){
        vec[mainIndex++] = L2[index2++];
    }
}

void mergeSort(vector<int> &vec, int l, int r){
    if(l < r){
        int mid = l + (r-l)/2;
        mergeSort(vec, l, mid);
        mergeSort(vec, mid+1, r);
        merge(vec, l, r);
    }
    else{
        return;
    }

}
int main(){
    vector<int> vec{1,2,1,5,3,6,3,8,7,9,3,4,7,23,1};
    vector<int>:: iterator it1, it2;
    cout<<"Before sorting: ";
    for(it1 = vec.begin() ; it1 != vec.end() ; it1++){
        cout<<*it1<<" ";
    }
    cout<<'\n';
    mergeSort(vec, 0, vec.size()-1);
    cout<<"After sorting: ";
    for(it2 = vec.begin() ; it2 != vec.end() ; it2++){
        cout<<*it2<<" ";
    }
    cout<<'\n';
    return 0;
}