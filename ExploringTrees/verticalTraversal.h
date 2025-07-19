#ifndef VERTICALTRAVERSAL_H
#define VERTICALTRAVERSAL_H

#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

class VerticalTraversal{
    map<int, vector<int>> mp;
    queue<pair<Node* , int>> q;
    public:
    void verticalTraversal(Node* root);
    void print(map<int, vector<int>>);

};

void VerticalTraversal::verticalTraversal(Node* root){
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node* , int> front = q.front();
        q.pop();
        Node* frontNode = front.first;
        int hd = front.second;
        mp[hd].push_back(frontNode->data);
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    print(mp);
}

void VerticalTraversal::print(map<int, vector<int>> mp){
    for(pair<int, vector<int>> x: mp){
        for(int i : x.second){
            cout<<i<<" ";
        }
    }
}

#endif