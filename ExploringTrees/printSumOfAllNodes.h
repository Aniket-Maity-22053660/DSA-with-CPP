#ifndef PRINTSUMOFALLNODES_H
#define PRINTSUMOFALLNODES_H

#include<iostream>

using namespace std;

class SumOfAllNodes{
    public:
    int findSum(Node* root){
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        sum += root->data;

        sum += findSum(root->left);
        sum += findSum(root->right);
        return sum;
    }
};

#endif