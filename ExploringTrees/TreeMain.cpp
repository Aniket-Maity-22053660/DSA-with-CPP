#include<iostream>
#include<vector>
#include "BuildTrees.h"
#include "levelOrderTraversal.h"
#include "preOrderTraversal.h"
#include "inOrderTraversal.h"
#include "postOrderTraversal.h"
#include "countLeafNodes.h"
#include "findHeight.h"
#include "findDiameter.h"
#include "IsBalanced.h"
#include "IsIdentical.h"
#include "IsSumTree.h"
#include "printZigZagTree.h"
#include "printBoundaryNodes.h"
#include "verticalTraversal.h"
#include "printTopView.h"
#include "printBottomView.h"
#include "printLeftView.h"
#include "printRightView.h"
//#include "printDiagonalTraversal.h"
#include "sumOfLongestBloodLine.h"
#include "DiagonalTraversal-II.h"
#include "lowestCommonAncestor.h"
#include "printSumOfAllNodes.h"
#include "kSumPaths.h"
#include "KthAncestor.h"
#include "constructBinaryTreeFromPreAndIn.h"

using namespace std;

int main(){
    Node* root = NULL;
    Node* root2 = NULL; 

    cout<<"Enter data from tree-1:- "<<endl;
    root = BuildTree(root);
    cout<<'\n';
    cout<<"Enter data from tree-2:- "<<endl;
    root2 = BuildTree(root2);
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
    cout<<'\n';
    CheckIsIdentical* objIdentical = new CheckIsIdentical();
    cout<<"Tree-1 and Tree-2 identical? ";
    cout<<(objIdentical->Check(root, root2) ? "Yes!" : "No!")<<endl;
    cout<<'\n';
    CheckIsSumTree* objSum = new CheckIsSumTree();
    cout<<"Tree is a sum-tree? ";
    cout<<(objSum->IsSumTree(root) ? "Yes" : "No")<<endl;
    cout<<'\n';
    cout<<"Printing zig-zag tree traversal:- "<<endl;
    PrintZigZag* objZigZag = new PrintZigZag();
    vector<int> vec = objZigZag->print(root);
    vector<int>::iterator it;
    for(it = vec.begin() ; it != vec.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<'\n';
    cout<<'\n';
    BoundaryNodes* objBoundary = new BoundaryNodes();
    cout<<"Printing boundary nodes of the tree:- "<<endl;
    objBoundary->printBoundary(root);
    cout<<'\n';
    cout<<'\n';
    VerticalTraversal* objVertical = new VerticalTraversal();
    cout<<"Printint vertical tree traversal:- "<<endl;
    objVertical->verticalTraversal(root);
    cout<<'\n';
    cout<<'\n';
    TopView* objTop = new TopView();
    cout<<"Printing top view of the tree:- "<<endl;
    objTop->printTopView(root);
    cout<<'\n';
    cout<<'\n';
    BottomView* objBottom = new BottomView();
    cout<<"Printing bottom view of the tree:- "<<endl;
    objBottom->printBottomView(root);
    cout<<'\n';
    cout<<'\n';
    LeftView* objLeft = new LeftView();
    cout<<"Printing left view of the tree:- "<<endl;
    objLeft->printLeftView(root);
    cout<<'\n';
    cout<<'\n';
    RightView* objRight = new RightView();
    cout<<"Printing right view of the tree:- "<<endl;
    objRight->printRightView(root);
    cout<<'\n';
    cout<<'\n';
   /* DiagonalTraversal* objDiag = new DiagonalTraversal();
    cout<<"Printing diagonal traversal of the tree:- "<<endl;
    objDiag->printDiagonalTraversal(root);
    cout<<'\n';
    cout<<'\n';
    */
    SumOfLongestBloodLine* objBlood = new SumOfLongestBloodLine();
    cout<<"Sum of longest blood line in a tree: ";
    cout<<objBlood->sumOfLongestBloodLine(root);
    cout<<'\n';
    cout<<'\n';
    DiagonalTraversal* objDiag = new DiagonalTraversal();
    cout<<"Printing diagonal traversal:- "<<endl;
    objDiag->diagonalTraversal(root2);
    cout<<'\n';
    cout<<'\n';
    int n1, n2;
    cout<<"Printing lowest common ancestor of two nodes:- "<<endl;
    cout<<"Enter the value of node1: ";
    cin>>n1;
    cout<<"Enter the value of node2: ";
    cin>>n2;
    LowestCommonAncestor* objCommon = new LowestCommonAncestor(n1, n2);
    Node* ans = objCommon->lowestCommonAncestor(root2);
    cout<<"Lowest Common ancestor: "<<ans->data;
    cout<<'\n';
    cout<<'\n';
    SumOfAllNodes* obj2 = new SumOfAllNodes();
    cout<<"Sum: "<<obj2->findSum(root2)<<endl;
    cout<<'\n';
    cout<<'\n';
    cout<<"Value of K sum paths:- "<<endl;
    KSumPaths* objKSum = new KSumPaths(8);
    cout<<"No of paths: "<<objKSum->kSum(root2);
    cout<<'\n';
    cout<<'\n';
    KthAncestor* objKthAncestor = new KthAncestor();
    cout<<objKthAncestor->findKthAncestor(root2);
    cout<<'\n';
    cout<<'\n';
    cout<<"Constructing Binary tree from pre-order and In-order traversal:- "<<endl;
    ConstructBinaryTreeFromInPre* objConstructTree = new ConstructBinaryTreeFromInPre();
    objConstructTree->ConstructTree();
    cout<<'\n';
    return 0;
}

