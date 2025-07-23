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
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
            Node* predecessor = root->left;
            while(predecessor->right != NULL){
                predecessor = predecessor->right;
            }
            root->data = predecessor->data;
            root->left = deleteNode(root->left, root->data);
        }
    }
    return root;
}


#endif