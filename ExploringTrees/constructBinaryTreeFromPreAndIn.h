#ifndef CONSTRUCTBINARYTREEFROMPREANDIN_H
#define CONSTRUCTBINARYTREEFROMPREANDIN_H

#include<iostream>
#include<vector>

using namespace std;

class ConstructBinaryTreeFromInPre{
    vector<int> InOrder;
    vector<int> PreOrder;

    void postOrder(Node*);
    Node* Construct(int, int, int);
    int findPos(int, vector<int>);
    public:
    ConstructBinaryTreeFromInPre(){
        int num1, num2, data;
        cout<<"Enter the number of values for in-order traversal: ";
        cin>>num1;
        cout<<"Enter the values for in-order traversal:- "<<endl;
        for(int i = 0 ; i < num1 ; i++){
            cout<<"Enter value "<<(i+1)<<": ";
            cin>>data;
            InOrder.push_back(data);
        }
        cout<<"Enter the number of values for pre-order traversal: ";
        cin>>num2;
        cout<<"Enter the values for pre-order traversal:- "<<endl;
        for(int i = 0 ; i < num2 ; i++){
            cout<<"Enter value "<<(i+1)<<": ";
            cin>>data;
            PreOrder.push_back(data);
        }
    }
    void ConstructTree();
};

void ConstructBinaryTreeFromInPre::ConstructTree(){
    int index = 0;
    Node* root = Construct(index, 0, InOrder.size()-1);
    postOrder(root);
}

Node* ConstructBinaryTreeFromInPre::Construct(int &index, int startIn, int endIn){
    if(index >= InOrder.size() || startIn > endIn){
        return NULL;
    }
    int element = PreOrder[index++];
    int position = findPos(element, InOrder);
    Node* root = new Node(element);
    root->left = Construct(index, startIn, position-1);
    root->right = Construct(index, position+1, endIn);
    return root;
}

int ConstructBinaryTreeFromInPre::findPos(int element, vector<int> InOrder){
    for(int i = 0 ; i < InOrder.size() ; i++){
        if(InOrder[i] == element){
            return i;
            break;
        }
    }
    return -1;
} 

void ConstructBinaryTreeFromInPre::postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return;
}

#endif