#ifndef KTHSMALLESTINBST_H
#define KTHSMALLESTINBST_H

#include<iostream>
#include "Node.h"

using namespace std;

class KthSmallestInBST{
    bool found = false;
    public:
    int findKthSmallest(Node* root, int &K){
        
        int ans = -1;
        if(root == NULL){
            return ans;
        }
        ans = findKthSmallest(root->left, K);
        if(!found){
        K--;
        }
        if(K == 0){
            ans = root->data;
            found = true;
        }
        if(!found){
            ans = findKthSmallest(root->right, K);
        }
        return ans;
    }
};

#endif