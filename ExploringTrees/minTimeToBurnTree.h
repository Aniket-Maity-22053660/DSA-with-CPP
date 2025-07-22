#ifndef MINTIMETOBURNTREE_H
#define MINTIMETOBURNTREE_H

#include<iostream>
#include<map>
#include<queue>

using namespace std;

class BurningTree{
    map<Node*, Node*> parentMap;
    Node* targetNode = NULL;
    int time = 0, target;
    void nodeToParent(Node* root, int element);
    public:
    BurningTree(){
        cout<<"Finding minimum time to burn the entire tree:- "<<endl<<endl;
        cout<<"Enter the starting node to burn: ";
        cin>>target;
    }
    int timeToBurn(Node* root);
};

int BurningTree::timeToBurn(Node* root){
    nodeToParent(root, target);
    queue<Node*> q;
    map<Node*, bool> visited;
    q.push(targetNode);
    visited[targetNode] = 1;
    while(!q.empty()){
        int totalBurningNodes = q.size();
        int flag = 0;
        for(int i = 0 ; i < totalBurningNodes ; i++){
            Node* burning = q.front();
            q.pop();
            if(burning->left && !visited[burning->left]){
                flag = 1;
                visited[burning->left] = 1;
                q.push(burning->left);
            }
            if(burning->right && !visited[burning->right]){
                flag = 1;
                visited[burning->right] = 1;
                q.push(burning->right);
            }
            if(parentMap[burning] && !visited[parentMap[burning]]){
                flag = 1;
                visited[parentMap[burning]] = 1;
                q.push(parentMap[burning]);
            }
        }
        if(flag == 1){
            time++;
        }
    }
    return  time;
}

void BurningTree::nodeToParent(Node* root, int element){
    queue<Node*> q;
    q.push(root);
    parentMap[root] = NULL;
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode->data == element){
            targetNode = frontNode;
        }
        if(frontNode->left){
            parentMap[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }
        if(frontNode->right){
            parentMap[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
}

#endif