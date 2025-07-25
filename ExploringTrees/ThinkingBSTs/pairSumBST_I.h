#ifndef PAIRSUMBST_I_H
#define PAIRSUMBST_I_H

#include<iostream>
#include<vector>
#include "Node.h"


class PairSumBST_I{
    int target;
    Node* topRoot;
    vector<int> pair;
    bool findPair(Node*, int, vector<int>&, Node*);
    public:
    PairSumBST_I(int data, Node* root){
        target = data;
        topRoot = root;
    }
    bool findPairSum(Node* root);
    vector<int> getPair();
};

vector<int> PairSumBST_I::getPair(){
    return pair;
}

bool PairSumBST_I::findPair(Node* root, int rem, vector<int> &pair, Node* exclude){
    if(!root){
        return false;
    }
    
    bool ans = false;
    if(root->data == rem && root != exclude){
        pair.push_back(exclude->data);
        pair.push_back(rem);
        return true;
    }
    ans = findPair(root->left, rem, pair, exclude);
    if(!ans){
        ans = findPair(root->right, rem, pair, exclude);
    }
    return ans;
}
bool PairSumBST_I::findPairSum(Node* root){
    if(!root){
        return false;
    }
    int rem = target - root->data;
    bool ans = false;
    ans = findPair(topRoot, rem, pair, root);
    if(!ans){
    ans = findPairSum(root->left);
    if(!ans){
        ans = findPairSum(root->right);
    }
    }
    return ans;
}

#endif
