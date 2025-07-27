#include<iostream>

using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    int totalNodes(Node* root){
        if(!root){
            return 0;
        }
        int lCount = 0, rCount = 0;
        lCount = totalNodes(root->left);
        rCount = totalNodes(root->right);
        return lCount + rCount + 1;
    }
    bool checkComplete(Node* root, int index, int totalCount){
        if(!root){
            return true;
        }
        if(index >= totalCount){
            return false;
        }
        bool left, right;
        left = checkComplete(root->left, 2*index + 1, totalCount);
        if(left){
            right = checkComplete(root->right, 2*index + 2, totalCount);
        }
        if(left && right){
            return true;
        }
        return false;
    }
    bool checkMaxHeap(Node* root){
        if(!root){
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }
        bool left, right;
        left = checkMaxHeap(root->left);
        if(left){
            right = checkMaxHeap(root->right);
        }
        if(left && right){
            if(root->left != NULL && root->right != NULL){
                if(root->data > root->left->data && root->data > root->right->data){
                    return true;
                }
            }else if(root->left == NULL){
                if(root->data > root->right->data){
                    return true;
                }
            }else{
                if(root->data > root->left->data){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isHeap(Node* tree) {
        // code here
        int totalCount = totalNodes(tree);
        bool isComplete = checkComplete(tree, 0, totalCount);
        return isComplete && checkMaxHeap(tree);
        
    }
};