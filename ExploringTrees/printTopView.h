#ifndef PRINTTOPVIEW_H
#define PRINTTOPVIEW_H

#include<iostream>
#include<map>
#include<queue>
#include<utility>

using namespace std;

class TopView{
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    public:
    void printTopView(Node*);
    void print(map<int, int>);
};

void TopView::printTopView(Node* root){
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> front = q.front();
        q.pop();
        Node* frontNode = front.first;
        int hd = front.second;
        if(mp.find(hd) == mp.end()){
            mp[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    print(mp);
}

void TopView::print(map<int, int> mp){
    for(pair<int, int> x : mp){
        cout<<x.second<<" ";
    }
}

#endif