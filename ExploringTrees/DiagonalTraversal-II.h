#ifndef DIAGONALTRAVERSAL_H
#define DIAGONALTRAVERSAL_H

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class DiagonalTraversal{
    queue<Node*> q;
    vector<int> ans;
    public:
    void diagonalTraversal(Node*);
    void print(vector<int>);
};

void DiagonalTraversal::diagonalTraversal(Node* root){
    if(root == NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        
        while(frontNode){
            ans.push_back(frontNode->data);
            if(frontNode->left){
                q.push(frontNode->left);
            }
            frontNode = frontNode->right;
        }
    }
    print(ans);
}

void DiagonalTraversal::print(vector<int> ans){
    vector<int>::iterator it;
    for(it = ans.begin() ; it != ans.end() ; it++){
        cout<<*it<<" ";
    }
}

#endif 