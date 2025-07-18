#ifndef  ISIDENTICAL_H
#define ISIDENTICAL_H

#include<iostream>

using namespace std;

class CheckIsIdentical{
    bool left = false, right = false, ans = false;
    public:
    bool Check(Node* root1, Node* root2);
};

bool CheckIsIdentical::Check(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    } 
    left = Check(root1->left, root2->left);
    if(left){
        right = Check(root1->right, root2->right);
    }
    if(left && right){
        ans = (root1->data == root2->data);
    }
    if(left && right && ans){
        return true;
    }
    else{
        return false;
    }
}

#endif