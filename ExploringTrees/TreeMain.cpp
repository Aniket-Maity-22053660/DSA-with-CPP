#include<iostream>
#include "BuildTrees.h"
#include "levelOrderTraversal.h"
#include "preOrderTraversal.h"
#include "inOrderTraversal.h"
#include "postOrderTraversal.h"


using namespace std;

int main(){
    Node* root = NULL;

    root = BuildTree(root);
    cout<<'\n';
    cout<<"Level order tree traversal:- "<<endl;
    LevelOrderTraversal *objLevel = new LevelOrderTraversal(root);
    objLevel->Traverse();
    cout<<'\n';
    cout<<"Pre-order tree traversal:- "<<endl;
    PreOrderTraversal* objPre = new PreOrderTraversal(root);
    objPre->Traverse(root);
    cout<<'\n';
    cout<<'\n';
    cout<<"In-order tree traversal:- "<<endl;
    InOrderTraversal* objIn = new InOrderTraversal();
    objIn->Traverse(root);
    cout<<'\n';
    cout<<'\n';
    cout<<"Post-order tree traversal:- "<<endl;
    PostOrderTraversal* objPost= new PostOrderTraversal();
    objPost->Traverse(root);
    cout<<'\n';
    return 0;
}