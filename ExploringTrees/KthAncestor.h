#ifndef KTHANCESTOR_H
#define KTHANCESTOR_H

#include<iostream>
#include<list>

using namespace std;

class KthAncestor{
    list<int> li;
    int K, node;
    bool isFound = false;
    void find(Node* root);
    public:
    KthAncestor(){
        cout<<"Finding the value of Kth ancestor of a node:- "<<endl;
        cout<<"Enter the value of K: ";
        cin>>K;
        cout<<"Enter the value of the node: ";
        cin>>node;
    }
    int findKthAncestor(Node* root);
    
};

int KthAncestor::findKthAncestor(Node* root){
    find(root);
    if(isFound){
        if(K <= li.size() - 1){
            int Ksize = K;
            for(int i = li.size() - 2 ; i >= 0 ; i++){
                if(K == 0){
                    break;
                }
                K--;
                li.pop_back();
            }
            cout<<"Printing "<<Ksize<<"th ancestor of "<<node<<": ";
            return li.back();
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

void KthAncestor::find(Node* root){
    if(root == NULL){
        return;
    }
    if(root->data == node){
        isFound = true;
        li.push_front(root->data);
        return;
    }
    find(root->left);
    if(!isFound){
    find(root->right);
    }
    if(isFound){
        li.push_front(root->data);
    }
    return;
}

#endif