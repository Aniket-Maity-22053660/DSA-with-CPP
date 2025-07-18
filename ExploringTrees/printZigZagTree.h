#ifndef PRINTZIGZAGTREE_H
#define PRINTZIGZAGTREE_H

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class PrintZigZag{
    vector<int> result;
    bool leftToRight = true;
    public:
    vector<int> print(Node* root){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size  = q.size();
            vector<int> ans(size);
            for(int i = 0 ; i < size ; i++){
                Node* front = q.front();
                q.pop();
                int index = (leftToRight ? i : size - i - 1);
                ans[index] = front->data;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            for(int x : ans){
                result.push_back(x);
            }
            leftToRight = !leftToRight;
        }
        return result;
    }

};

#endif