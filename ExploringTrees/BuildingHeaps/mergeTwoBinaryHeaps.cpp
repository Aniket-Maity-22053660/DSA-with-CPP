#include<iostream>
#include<vector>

using namespace std;


class Solution {
    void swap(int i1, int i2, vector<int> &vec){
        int temp = vec.at(i1);
        vec.at(i1) = vec.at(i2);
        vec.at(i2) = temp;
    }
    void heapify(vector<int> &vec, int i){
        int largest = i;
        int left = 2*largest;
        int right = 2*largest + 1;
        if(left < vec.size() && vec[largest] < vec[left]){
            largest = left;
        }
        if(right < vec.size() && vec[largest] < vec[right]){
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
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> merged(1, INT_MAX);
        int i = 0 , j = 0;
        while(i < n && j < m){
            if(a.at(i) < b.at(j)){
                merged.push_back(a.at(i++));
            }else{
                merged.push_back(b.at(j++));
            }
        }
        while(i < n){
            merged.push_back(a.at(i++));
        }
        while(j < m){
            merged.push_back(b.at(j++));
        }
        make_heap(merged);
        vector<int> ans;
        for(int i = 1 ; i < merged.size() ; i++){
            ans.push_back(merged[i]);
        }
        return ans;
    }
};