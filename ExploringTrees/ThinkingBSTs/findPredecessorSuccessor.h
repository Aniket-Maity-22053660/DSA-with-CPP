#ifndef FINDPREDECESSORSUCCESSOR_H
#define FINDPREDECESSORSUCCESSOR_H

#include<iostream>
#include<vector>
#include "Node.h"

using namespace std;

class FindPredecessorSuccessor{
    vector<Node*> ans;
    public:
    vector<Node*>findPredecessorSuccessor(Node*, int);
};

vector<Node*> FindPredecessorSuccessor::findPredecessorSuccessor(Node* root, int key){
    Node* predecessorAns = NULL;
    Node* successorAns = NULL;
    while(root && root->data != key){
        if(key > root->data){
            predecessorAns = root;
            root = root->right;
        }
        else{
            successorAns = root;
            root = root->left;
        }
    }

    if(!root){
        return {predecessorAns, successorAns};
    }
    Node* predecessor = root->left;
    Node* successor = root->right;
    while(predecessor != NULL){
        predecessorAns = predecessor;
        predecessor = predecessor->right;
    }
    while(successor != NULL){
        successorAns = successor;
        successor = succssor->left;
    }
    return {predecessorAns, successorAns};
}

#endif