#ifndef COUNTLEAFNODES_H
#define COUNTLEAFNODES_H

#include<iostream>

using namespace std;

class CountLeafNodes{
    int count = 0;
    public:
    void countLeaf(Node* root){
        if(root == NULL){
            return;
        }
        countLeaf(root->left);
        countLeaf(root->right);
        if(root->left == NULL && root->right == NULL){
            count++;
        }
    }
    int getCount(){
        return count;
    }
};

#endif