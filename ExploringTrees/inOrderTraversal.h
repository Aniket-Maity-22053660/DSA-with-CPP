#ifndef INORDERTRAVERSAL_H
#define INORDERTRAVERSAL_H

#include<iostream>

using namespace std;

class InOrderTraversal{
    public:
    void Traverse(Node* root){
        if(root == NULL){
            return;
        }
        Traverse(root->left);
        cout<<root->data<<" ";
        Traverse(root->right);
    }
};

#endif