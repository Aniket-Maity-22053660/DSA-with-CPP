#ifndef ISBALANCED_H
#define ISBALANCED_H

#include<iostream>
#include<cmath>
#include "findHeight.h"

using namespace std;

class CheckIsBalanced{
    FindHeight* objHeight;
    bool left = false, right = false, diff = false;
    public:
    CheckIsBalanced(){
        objHeight = new FindHeight();
    }
    bool check(Node* root){
        if(root == NULL){
            return true;
        }
        left = check(root->left);
        if(left){
            right = check(root->right);
        }
        if(left && right){
            diff = abs(objHeight->find(root->left) - objHeight->find(root->right)) <= 1;
        }
        if(left && right && diff){
            return true;
        }
        return false;
    }

};

#endif
