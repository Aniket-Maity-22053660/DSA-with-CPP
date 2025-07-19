#ifndef PRINTRIGHTVIEW_H
#define PRINTRIGHTVIEW_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RightView{
    vector<int> vec;
    queue<Node*> q;
    public:
    void printRightView(Node*);
    void print(vector<int>);
};

void RightView::printRightView(Node* root){
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                Node* frontNode = q.front();
                q.pop();
                if(i == size - 1){
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

void RightView::print(vector<int> vec){
    vector<int>::iterator it;
    for(it = vec.begin() ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
}

#endif