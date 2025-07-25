#ifndef PAIRSUMBST_II_H
#define PAIRSUMBST_II_H

#include<iostream>
#include<set>
#include<vector>

class PairSumBST_II{
    set<int> seen;
    vector<int> pair;

    public:
    vector<int> getPair(){
        return pair;
    }
    bool findPairSum(Node* root, int target){
        if(!root){
            return false;
        }
        if(seen.count(target - root->data)){
            pair.push_back(root->data);
            pair.push_back(target - root->data);
            return true;
        }
        seen.insert(root->data);
        bool ans = false;
        ans = findPairSum(root->left, target);
        if(!ans){
            ans = findPairSum(root->right, target);
        }
        return ans;
    }
};

#endif