#include<iostream>
#include "buildBinarySearchTrees.h"
#include "../inOrderTraversal.h"
#include "Node.h"
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
    InOrderTraversal* objTraverseIn = new InOrderTraversal();
    cout<<"In-order traversal of Binary Search Tree:- "<<endl;
    objTraverseIn->Traverse(root);
    cout<<'\n';
    return 0;
}