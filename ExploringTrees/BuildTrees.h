#ifndef BUILDTREES_H
#define BUILDTREES_H

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BuildTree(Node* root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);

    cout<<"Enter the left of data "<<data<<":- "<<endl;
    root->left = BuildTree(root->left);
    cout<<"Enter the right of the data "<<data<<":- "<<endl;
    root->right = BuildTree(root->right);
    return root;
}


#endif