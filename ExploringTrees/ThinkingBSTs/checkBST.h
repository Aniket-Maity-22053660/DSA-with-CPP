#ifndef CHECKBST_H
#define CHECKBST_H

#include<iostream>
#include "Node.h"
#include<climits>

class CheckBST{
    bool checkBST(Node*, int, int);
    public:
    bool check(Node* root);
};

bool CheckBST::check(Node* root){
    bool ans = checkBST(root, INT_MIN, INT_MAX);
    return ans;
}

bool CheckBST::checkBST(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data >= min || root->data <= max){
        return false;
    }
    return (checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max) ? true : false);
}

#endif