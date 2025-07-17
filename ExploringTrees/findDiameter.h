#ifndef FINDDIAMETER_H
#define FINDDIAMETER_H

#include<iostream>
#include "findHeight.h"

using namespace std;

class FindDiameter{
    FindHeight* objHeight;
    int op1, op2, op3, maxi;
    public:
    FindDiameter(){
        objHeight = new FindHeight();
    };
    int findDiameter(Node* root){
        if(root == NULL){
            return 0;
        }
        op1 = findDiameter(root->left);
        op2 = findDiameter(root->right);
        op3 = objHeight->find(root->left) + objHeight->find(root->right) + 1;
        maxi = max(op1, max(op2, op3));
        return maxi;
    };
};

#endif