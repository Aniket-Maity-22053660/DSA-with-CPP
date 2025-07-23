#ifndef BUILDBINARYSEARCHTREES_H
#define BUILDBINARYSEARCHTREES_H

#include<iostream>
#include "Node.h"
using namespace std;

class BuildBSTs{
    public:
    Node* buildBST(Node* root, int data){
        if(root == NULL){
            Node* root = new Node(data);
            return root;
        }
        if(root->data > data){
            root->left = buildBST(root->left, data);
        }
        if(root->data < data){
            root->right = buildBST(root->right, data);
        }
        return root;
    }

};

#endif