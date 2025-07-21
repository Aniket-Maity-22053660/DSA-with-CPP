#ifndef MAXSUMOFNONADJACENTNODES_H
#define MAXSUMOFNONADJACENTNODES_H

#include<iostream>
#include<map>

using namespace std;

class MaxSumOfNonAdjacentNodes{
    map<Node*, int> dp;
    public:
    int MaxSum(Node* root);
};

int MaxSumOfNonAdjacentNodes::MaxSum(Node* root){
    if(root == NULL){
        return 0;
    }
    if(dp.find(root) != dp.end()){
        return dp[root];
    }
    int include = root->data;

    if(root->left){
        include += MaxSum(root->left->left);
        include += MaxSum(root->left->right);
    }
    if(root->right){
        include += MaxSum(root->right->left);
        include += MaxSum(root->right->right);
    }

    int exclude = MaxSum(root->left) + MaxSum(root->right);
    dp[root] = max(include, exclude);
    return dp[root];
}

#endif


