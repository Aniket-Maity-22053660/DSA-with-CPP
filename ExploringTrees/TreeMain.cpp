#include<iostream>
#include "BuildTrees.h"
#include "levelOrderTraversal.h"

using namespace std;

int main(){
    Node* root = NULL;

    root = BuildTree(root);
    cout<<'\n';
    cout<<"Level order tree traversal:- "<<endl;
    LevelOrderTraversal *obj1 = new LevelOrderTraversal(root);
    obj1->Traverse();
    return 0;
}