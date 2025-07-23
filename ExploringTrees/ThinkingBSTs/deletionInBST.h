#ifndef DELETIONINBST_H
#define DELETIONINBST_H

#include<iostream>
#include "Node.h"

using namespace std;

class DeletionInBST{
    public:
    Node* deleteNode(Node* root, int data);
};

Node* DeletionInBST::deleteNode(Node* root, int data){
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }else if(root->left == NULL){
            delete root;
            return root->right;
        }else if(root->right == NULL){
            delete root;
            return root->left;
        }else{
            Node* successor = root->left;
            while(successor->right != NULL){
                successor = successor->right;
            }
            root->data = successor->data;
            root->left = deleteNode(root->left, root->data);
        }
    }
    return root;
}


#endif