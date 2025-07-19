#ifndef PRINTDIAGONALTRAVERSAL_H
#define PRINTDIAGONALTRAVERSAL_H

#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

class DiagonalTraversal{
    vector<int> vec;
    queue<pair<Node*, int>> q;
    map<int, vector<int>> mp;
    public:
    void printDiagonalTraversal(Node*);
    void print(map<int, vector<int>>);
};

void DiagonalTraversal:: printDiagonalTraversal(Node* root){
    if(root == NULL){
        return;
    }
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> front = q.front();
        q.pop();
        Node* frontNode = front.first;
        int dg = front.second;
        mp[dg].push_back(frontNode->data);
        if(frontNode->left){
            q.push(make_pair(frontNode->left, dg-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, dg));
        }
    }
    print(mp);
}

void DiagonalTraversal::print(map<int, vector<int>> mp){
    for(pair<int, vector<int>> x : mp){
        for(int y : x.second){
            cout<<y<<" ";
        }
    }
};

#endif