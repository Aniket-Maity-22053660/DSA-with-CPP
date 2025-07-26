#ifndef FLATTENBINARYTREE_H
#define FLATTENBINARYTREE_H

#include<iostream>
#include "Node.h"

using namespace std;

class FlattenBinaryTree{
    Node* prev = NULL;
    void printFlatten(Node* root){
        if(!root){
            return;
        }
        if(root->left){
            cout<<1<<" ";
        }
        cout<<root->data<<" ";
        printFlatten(root->right);
        return;
    }
    void flatten(Node* &root){
        if(!root){
            return;
        }
        if(prev != NULL){
            prev->right = root;
        }
        prev = root;
        Node* right = root->right;
        flatten(root->left);
        root->left = NULL;
        flatten(right);
        return;
    }
    public:
    void flattenBinaryTree(Node* root){
        flatten(root);
        printFlatten(root);
        return;
    }
};

#endif