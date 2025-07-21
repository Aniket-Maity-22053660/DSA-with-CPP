#ifndef LOWESTCOMMONANCESTOR_H
#define LOWESTCOMMONANCESTOR_H

#include<iostream>

class LowestCommonAncestor{
    int n1, n2;
    public:
    LowestCommonAncestor(int n1, int n2){
        this->n1 = n1;
        this->n2 = n2;
    }
    Node* lowestCommonAncestor(Node*);
};

Node* LowestCommonAncestor::lowestCommonAncestor(Node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left, *right;
    left = lowestCommonAncestor(root->left);
    right = lowestCommonAncestor(root->right);
    if(left && right){
        return root;
    }else{
        return (left?left:right);
    }
}

#endif