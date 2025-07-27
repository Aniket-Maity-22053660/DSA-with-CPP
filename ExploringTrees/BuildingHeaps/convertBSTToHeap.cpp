#include<iostream>
#include<vector>

using namespace std;

// User function Template for C++

class Node{
    int data;
    Node* left, *right;
    public:
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    
    void inOrder(Node* root, vector<int> &vec){
        if(!root){
            return;
        }
        inOrder(root->left, vec);
        vec.push_back(root->data);
        inOrder(root->right, vec);
    }
    void convert(Node* &root, vector<int> &vec, int &index){
        if(!root){
            return;
        }
        convert(root->left, vec, index);
        convert(root->right, vec, index);
        root->data = vec.at(index++);
    }
  public:
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        int index = 0;
        vector<int> inArr;
        inOrder(root, inArr);
        convert(root, inArr, index);
    }
};
