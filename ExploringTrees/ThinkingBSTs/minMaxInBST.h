#ifndef MINMAXINBST_H
#define MINMAXINBST_H

#include<iostream>
#include<vector>
#include "Node.h"

class FindMinMax{
    Node* findMin(Node*);
    Node* findMax(Node*);
    public:
    vector<Node*> findMinMax(Node*);
};

Node* FindMinMax:: findMin(Node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL){
        return root;
    }
    Node* minNode = NULL;
    minNode = findMin(root->left);
    return minNode;
}

Node* FindMinMax:: findMax(Node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL){
        return root;
    }
    Node* maxNode = NULL;
    maxNode = findMax(root->right);
    return maxNode; 
}
vector<Node*> FindMinMax::findMinMax(Node* root){
    Node* min = findMin(root);
    Node* max = findMax(root);
    vector<Node*> ans {min, max};
    return ans;
}

#endif