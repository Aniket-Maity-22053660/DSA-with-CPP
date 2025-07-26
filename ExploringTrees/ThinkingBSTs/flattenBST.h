#ifndef FLATTENBST_H
#define FLATTENBST_H

#include<iostream>
#include "Node.h"
using namespace std;

class FlattenBST{
    Node* prev = NULL, *startNode = NULL;
    void flatten(Node* &root){
        if(!root){
            return;
        }
        flatten(root->left);
        Node* right = root->right;
        if(prev){
            prev->right  = root;
        }else{
            startNode = root;
        }
        prev = root;
        root->left = NULL;
        flatten(right);
        return;
    }
    void printFlatten(Node* root){
        if(!root){
            return;
        }
        cout<<root->data<<" ";
        if(root->left){
            cout<<1<<" ";
        }
        printFlatten(root->right);
        return;
    }
    public:
    void flattenBST(Node* root){
        flatten(root);
        printFlatten(startNode);
        return;
    }
};

#endif