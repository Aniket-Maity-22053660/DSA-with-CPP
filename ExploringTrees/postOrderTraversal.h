#ifndef POSTORDERTRAVERSAL_H
#define POSTORDERTRAVERSAL_H

#include<iostream>

using namespace std;

class PostOrderTraversal{
    public:
    void Traverse(Node* root){
        if(root == NULL){
            return;
        }
        Traverse(root->left);
        Traverse(root->right);
        cout<<root->data<<" ";
    }
};

#endif