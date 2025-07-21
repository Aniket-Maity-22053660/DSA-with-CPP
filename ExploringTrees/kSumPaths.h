#ifndef KSUMPATHS_H
#define KSUMPATHS_H

#include<iostream>

using namespace std;

class KSumPaths{
    int K;
    int findPath(Node* root, int K ,int sum){
        if(root == NULL){
            return 0;
        }
        int count = 0;
        sum += root->data;
        if(sum == K){
            count++;
        }
        count += findPath(root->left, K, sum);
        count += findPath(root->right, K, sum);
        return count;
    }
    public:
    KSumPaths(int K){
        this->K = K;
    }
    int kSum(Node* root){
        if(root == NULL){
            return 0;
        }
        int totalCount = findPath(root, K, 0);
        totalCount += kSum(root->left);
        totalCount += kSum(root->right
        );
        return totalCount;
        }
};

#endif