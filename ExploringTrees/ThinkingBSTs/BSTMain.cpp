#include<iostream>
#include "buildBinarySearchTrees.h"
#include "../inOrderTraversal.h"
#include "Node.h"
#include "searchInBST.h"
#include "deletionInBST.h"
#include "checkBST.h"
#include "kthSmallestInBST.h"
#include "findLCAInBST.h"

#include<vector>

using namespace std;



int main(){
    vector<int> vec;
    int size, data;
    cout<<"Enter the number of elements for the Binary Search Tree: ";
    cin>>size;
    vec.resize(size);
    for(int i = 0 ; i < vec.size() ; i++){
        cout<<"Enter the element "<<(i+1)<<": ";
        cin>>data;
        vec.at(i) = data;
    }
    Node* root = NULL;
    BuildBSTs* objBuild = new BuildBSTs();
    for(int i = 0 ; i < vec.size() ; i++){
        root = objBuild->buildBST(root, vec.at(i));
    }
    /*
    InOrderTraversal* objTraverseIn = new InOrderTraversal();
    cout<<"In-order traversal of Binary Search Tree:- "<<endl;
    objTraverseIn->Traverse(root);
    cout<<'\n';
    int element;
    cout<<"Searching in Binary Search Tree:- "<<endl;
    cout<<"Enter the element to search: ";
    cin>>element;
    SearchInBST* objSearch = new SearchInBST();
    Node* found = objSearch->searchBST(root, element);
    if(found){
        cout<<found->data<<" was found in the BST!"<<endl;
    }else{
        cout<<"The element was not found in the BST!"<<endl;
    }
    cout<<'\n';
    cout<<"Enter the element to be deleted from the BST: ";
    cin>>element;
    DeletionInBST* objDelete = new DeletionInBST();
    objDelete->deleteNode(root, element);
    cout<<"After deleting the node in-order traversal of the BST:- "<<endl;
    objTraverseIn->Traverse(root);
    cout<<'\n';
    cout<<"Is it a Binary Search Tree? ";
    CheckBST* objCheck = new CheckBST();
    cout<<(objCheck->check(root) ? "Yes!" : "No!")<<endl;
    cout<<'\n';
    cout<<"Finding the value of kth smallest element in BST:- "<<endl;
    int K;
    cout<<"Enter the value of K: ";
    cin>>K;
    cout<<K<<"th smallest element in the BST: ";
    KthSmallestInBST* objKthSmallest = new KthSmallestInBST();
    cout<<objKthSmallest->findKthSmallest(root, K);
    cout<<'\n';
    */
    LCAInBST* objLCA = new LCAInBST();
    cout<<"Finding LCA in a BST:- "<<endl;
    int n1, n2;
    cout<<"Enter the value of n1: ";
    cin>>n1;
    cout<<"Enter the value of n2: ";
    cin>>n2;
    Node* ans = objLCA->findLCA(root, n1, n2);
    cout<<"Lowest Common Ancestor: "<<ans->data<<endl;
    return 0;
}