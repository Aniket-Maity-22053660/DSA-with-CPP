#ifndef SUMOFLONGESTBLOODLINE_H
#define SUMOFLONGESTBLOODLINE_H

#include<iostream>
#include<utility>

using namespace std;

class SumOfLongestBloodLine{
    pair<int, int> longest = make_pair(0, 0);
    public:
    int sumOfLongestBloodLine(Node*);
    int calculateSum(Node*, int, int);
};

int SumOfLongestBloodLine::sumOfLongestBloodLine(Node*root){
    int ans = calculateSum(root, 0, 0);
    return ans;
}

int SumOfLongestBloodLine::calculateSum(Node* root, int sum, int length){
    if(root == NULL){
        if(length > longest.second){
            longest = make_pair(sum, length);
        }
        else if(length == longest.second){
            longest = make_pair(max(sum, longest.first), length);
        }
        return longest.first; 
    }
    sum = sum + root->data;
    length = length + 1;
    calculateSum(root->left, sum, length);
    calculateSum(root->right, sum, length);
    return longest.first;
}

#endif