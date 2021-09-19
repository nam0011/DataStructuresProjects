//---------------------------------------------------------------
// File: Code204_Tree.h
// Purpose: Header file for a demonstration of a binary tree
// Programming Language: C++
// Author: Dr. Rick Coleman
//---------------------------------------------------------------

#include <iostream>

using namespace std;

// Define a structure to be used as the tree node
struct Node
{
    int      Key;
    float    fValue;
    int      iValue;
    char     cArray[7];
    Node *left;
    Node *right;
};

class playerTree
{
private:
    Node *root;

public:
    playerTree();
    ~playerTree();

    void createTree();
    bool isEmpty();
    Node *SearchTree(int Key);
    bool Insert(Node *newNode);
    bool Insert(int Key, float f, int i, char *cA);
    Node *Delete(int Key);
    void PrintOne(Node *T);
    void PrintTree();
private:
    void ClearTree(Node *T);
    Node *DupNode(Node * T);
    void PrintAllForward(Node *T);
};

