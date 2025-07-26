#ifndef MERGETWOBXT_H
#define MERGETWOBST_H

#include<iostream>
#include<vector>
#include "Node.h"


class MergeTwoBSTs{
    vector<int> BST1;
    vector<int> BST2;
    Node* root1, *root2;

    void traverseIn(Node* root, vector<int> &BST){
        if(!root){
            return;
        }
        traverseIn(root->left, BST);
        BST.push_back(root->data);
        traverseIn(root->right, BST);
        return;
    }
    vector<int> merge(){
        vector<int> vec;
        int i = 0 , j = 0;
        while(i < BST1.size() && j < BST2.size()){
            if(BST1[i] < BST2[j]){
                vec.push_back(BST1[i]);
                i++;
            }else{
                vec.push_back(BST2[j]);
                j++;
            }
        }
        while(i < BST1.size()){
            vec.push_back(BST1[i++]);
        }
        while(j < BST2.size()){
            vec.push_back(BST2[j++]);
        }
        return vec;
    }
    void printIn(vector<int> merged){
        vector<int>::iterator it;
        for(it = merged.begin() ; it != merged.end() ; it++){
            cout<<*it<<" ";
        }
        return;
    }
    public:
    MergeTwoBSTs(Node* root1, Node* root2){
        this->root1 = root1;
        this->root2 = root2;
    }
    void mergeTwoBSTs(){
        traverseIn(root1, BST1);
        traverseIn(root2, BST2);
        cout<<"Printing the first BST (inorder): ";
        printIn(BST1);
        cout<<'\n';
        cout<<"Printing the second BST (inorder): ";
        printIn(BST2);
        cout<<'\n';
        vector<int> merged = merge();
        cout<<"Printing the merged BST: ";
        printIn(merged);
        cout<<'\n';
    }
};

#endif