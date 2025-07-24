#ifndef CHECKBST_H
#define CHECKBST_H

#include<iostream>
#include "Node.h"

class CheckBST{
    public:
    bool check(Node* root);
};

bool CheckBST::check(Node* root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    bool left = check(root->left);
    bool right;
    if(left){
        right = check(root->right);
    }
    if(left && right){
        if(root->left == NULL){
            if(root->right->data > root->data){
                return true;
            }
        }else if(root->right == NULL){
            if(root->left->data < root->data){
                return true;
            }
        }else if(root->left != NULL && root->right != NULL){
            if(root->data > root->left->data && root->data < root->right->data){
                return true;
            }
        }
    }
    return false;
}

#endif