#ifndef LEVELORDERTRAVERSAL_H
#define LEVELORDERTRAVERSAL_H

#include<iostream>
#include<queue>
using namespace std;

class LevelOrderTraversal{
    public:
    Node* root;
    LevelOrderTraversal(Node* root){
        this->root = root;
    }
    void Traverse(){
        queue<Node*> q;
        if(root){
            q.push(root);
            while(!q.empty()){
                Node* front = q.front();
                q.pop();
                cout<<front->data<<" ";
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            cout<<'\n';
        }else{
            cout<<"Tree is empty!"<<endl;
            return;
        }
    }
};

#endif