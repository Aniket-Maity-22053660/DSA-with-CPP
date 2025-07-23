#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int data): left(NULL), right(NULL), data(data) {};
};

#endif