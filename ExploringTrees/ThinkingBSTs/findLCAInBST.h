#ifndef FINDLCAINBST_H
#define FINDLCAINBST_H

#include<iostream>
#include "Node.h"

using namespace std;

class LCAInBST{
    public:
    Node* findLCA(Node*, int, int);
};

Node* LCAInBST::findLCA(Node* root, int n1, int n2){
    Node* ans = root;
    if(root->data == n1 || root->data == n2 || (root->data < n1 && root->data > n2) || (root->data > n1 && root->data < n2)){
        return ans;
    }
    if(root->data > n1 && root->data > n2){
        ans = findLCA(root->left, n1, n2);
    }
    if(root->data < n1 && root->data < n2){
        ans = findLCA(root->right, n1, n2);
    }
    return ans;
}

#endif