#ifndef PREORDERTRAVERSAL_H
#define PREORDERTRAVERSAL_H

class PreOrderTraversal{
    public:
    Node* root;
    PreOrderTraversal(Node* root){
        this->root = root;
    }
    void Traverse(Node* root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" ";
        Traverse(root->left);
        Traverse(root->right);
    }
};

#endif