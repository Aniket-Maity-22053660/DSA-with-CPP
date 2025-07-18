#ifndef PRINTBOUNDARYNODES_H
#define PRINTBOUNDARYNODES_H

#include<iostream>
#include<vector>

using namespace std;

class BoundaryNodes{
    public:
    vector<int> ans;
    void traverseLeft(Node* root);
    void traverseRight(Node* root);
    void traverseLeaf(Node* root);
    void printBoundary(Node* root);
    void print(vector<int>);
};

void BoundaryNodes::printBoundary(Node* root){
    if(root == NULL){
        print(ans);
        return; 
    }
    if(!(root->left == NULL && root->right == NULL)){
        ans.push_back(root->data);
    }
    traverseLeft(root->left);
    traverseLeaf(root);
    traverseRight(root->right);
    print(ans);
    return;
}

void BoundaryNodes::traverseLeft(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left);
    }else{
        traverseLeft(root->right);
    }
    return;
}

void BoundaryNodes::traverseRight(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right){
        traverseRight(root->right);
        ans.push_back(root->data);
    }else{
        traverseRight(root->left);
        ans.push_back(root->data);
    }
    return;
}
void BoundaryNodes::traverseLeaf(Node* root){
    if(root == NULL){
        return;
    }
    traverseLeaf(root->left);
    traverseLeaf(root->right);
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    return;
}
void BoundaryNodes::print(vector<int> vec){
    vector<int>:: iterator it;
    if(vec.size() > 0){
    for(it = vec.begin() ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
}else{
    cout<<"Tree is empty!";
}
}

#endif