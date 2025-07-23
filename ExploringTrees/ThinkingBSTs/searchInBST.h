#ifndef SEARCHINBST_H
#define SEARCHINBST_H

#include<iostream>
#include "Node.h"

using namespace std;

class SearchInBST{
    public:
    Node* searchBST(Node* root, int data){
        if(root == NULL){
            return NULL;
        }
        if(root->data == data){
            return root;
        }
        Node* ans;
        if(data > root->data){
            ans = searchBST(root->right, data);
        }
        else{
            ans = searchBST(root->left, data);
        }
        return ans;
    }
};

#endif