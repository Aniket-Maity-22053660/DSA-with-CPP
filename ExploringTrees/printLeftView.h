#ifndef PRINTLEFTVIEW_H
#define PRINTLEFTVIEW_H

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class LeftView{
    queue<Node* > q;
    vector<int> vec;
    public:
    void printLeftView(Node*);
    void print(vector<int>);
};


void LeftView::printLeftView(Node* root){
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i < size ; i++){
            Node* frontNode = q.front();
            q.pop();
            if(i == 0){
                vec.push_back(frontNode->data);
            }
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }
    print(vec);
}

void LeftView::print(vector<int> vec){
    vector<int>::iterator it;
    for(it = vec.begin() ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
}

#endif