#include<iostream>
#include "BuildTrees.h"
#include "levelOrderTraversal.h"
#include "preOrderTraversal.h"
#include "inOrderTraversal.h"
#include "postOrderTraversal.h"
#include "countLeafNodes.h"
#include "findHeight.h"
#include "findDiameter.h"
#include "IsBalanced.h"

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
    cout<<'\n';
    cout<<"Count of leaf nodes: ";
    CountLeafNodes* objCount = new CountLeafNodes();
    objCount->countLeaf(root);
    cout<<objCount->getCount();
    cout<<'\n';
    cout<<'\n';
    cout<<"Height of the tree: ";
    FindHeight* objHeight = new FindHeight();
    cout<<objHeight->find(root);
    cout<<'\n';
    cout<<'\n';
    FindDiameter* objDiameter = new FindDiameter();
    cout<<"Diameter of the tree: ";
    cout<<objDiameter->findDiameter(root);
    cout<<'\n';
    cout<<'\n';
    cout<<"Balanced tree?  ";
    CheckIsBalanced* objBalanced = new CheckIsBalanced();
    cout<<(objBalanced->check(root) ? "Yes!" : "No!")<<endl;
    return 0;
}