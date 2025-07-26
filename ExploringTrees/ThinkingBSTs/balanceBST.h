#ifndef BALANCEBST_H
#define BALANCEBST_H

#include<iostream>
#include<vector>
#include "Node.h"

using namespace std;

class BalanceBST{
    vector<Node* > inOrder;
    void traverseIn(Node* root){
        if(!root){
            return;
        }
        traverseIn(root->left);
        inOrder.push_back(root);
        traverseIn(root->right);
        return;
    }
    void traversePre(Node* root){
        if(!root){
            return;
        }
        cout<<root->data<<" ";
        traversePre(root->left);
        traversePre(root->right);
        return;
    }
    Node* balance(int s, int e){
        if(s <= e){
        int mid = (s + e) / 2;
        Node* node = new Node((inOrder.at(mid))->data);
        node->left = balance(s, mid - 1);
        node->right = balance(mid+1, e);
        return node;
        }else{
            return NULL;
        }
    }

    public:
    void balanceBST(Node* root){
        traverseIn(root);
        cout<<"Before balancing the tree: ";
        traversePre(root);
        cout<<'\n';
        Node* newRoot = balance(0, inOrder.size() - 1);
        cout<<"After balancing the tree: ";
        traversePre(newRoot);
        cout<<'\n';
    }
};

#endif