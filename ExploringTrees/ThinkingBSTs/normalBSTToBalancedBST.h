#ifndef NORMALBSTTOBALANCEDBST_H
#define NORMALBSTTOBALANCEDBST_H

#include<iostream>
#include "Node.h"
#include<vector>

using namespace std;

class NormalToBalancedBST{
    vector<int> inOrder;
    void traverseIn(Node* root){
        if(!root){
            return;
        }
        traverseIn(root->left);
        inOrder.push_back(root->data);
        traverseIn(root->right);
        return;
    }
    Node* convert(int s, int e){
        if(s <= e){
            int mid = (s + e) / 2;
            Node* node = new Node(inOrder.at(mid));
            node->left = convert(s, mid - 1);
            node->right = convert(mid + 1, e);
            return node;
        }else{
            return NULL;
        }
    }
    void printIn(Node* root){
        if(!root){
            return;
        }
        printIn(root->left);
        cout<<root->data<<" ";
        printIn(root->right);
        return;
    }
    public:
    void normalToBalancedBST(Node* root){
        cout<<"Normal BST: ";
        printIn(root);
        traverseIn(root);
        Node* ans = convert(0, inOrder.size() - 1);
        cout<<"Balanced BST: ";
        printIn(ans);
        return;
    }
};

#endif