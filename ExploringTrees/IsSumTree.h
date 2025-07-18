#ifndef ISSUMTREE_H
#define ISSUMTREE_H

#include<iostream>

using namespace std;

class CheckIsSumTree{
    bool IsSumTree(Node* root, int &sum);
    bool leftSum = false, rightSum = false;
    public:
    bool IsSumTree(Node* root);
};

bool CheckIsSumTree:: IsSumTree(Node* root, int &sum){
    if(root == NULL){
        sum = 0;
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        sum = root->data;
        return true;
    }
    int left = 0, right = 0;
    leftSum = IsSumTree(root->left, left);
    if(leftSum){
        rightSum = IsSumTree(root->right, right);
    }
   
    if(leftSum && rightSum && (root->data == left + right)){
        sum = root->data + left + right;
        return true;
    }else{
        return false;
    }
    
}

bool CheckIsSumTree:: IsSumTree(Node* root){
    int sum = 0;
    bool ans = IsSumTree(root, sum);
    //cout<<"Sum is "<<sum<<endl;
    return ans;
}

#endif
