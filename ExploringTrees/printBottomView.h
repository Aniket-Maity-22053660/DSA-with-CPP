#ifndef PRINTBOTTOMVIEW_H
#define PRINTBOTTOMVIEW_H

#include<iostream>
#include<map>
#include<queue>
#include<utility>

using namespace std;

class BottomView{
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    public:
    void printBottomView(Node* root);
    void print(map<int, int>);
};

void BottomView::printBottomView(Node* root){
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> front = q.front();
        q.pop();
        Node* frontNode = front.first;
        int hd = front.second;
        mp[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    print(mp);
}

void BottomView::print(map<int, int> mp){
    for(pair<int, int> x : mp){
        cout<<x.second<<" ";
    }
}

#endif