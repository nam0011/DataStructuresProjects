#include <iostream>
#include "Player.h"
using namespace std;

class TreeNode{
public:
    Player item;
    string      Key;
    string    first;
    string      last;
    double     batAVG;
    double     slug;
    double     oPS;
    TreeNode *left;
    TreeNode *right;
};

class Node {    //creation of class Node

public: //public variables and functions
    Player item;
    Node *pNext;
    Node(const Player &playerIn);
    Node *pPrev;
    string key;
};

class PlayerList{
public:
    PlayerList();
    ~PlayerList();
    bool isEmpty();
    TreeNode *SearchTree(string Key);
    bool Insert(TreeNode *newNode);
    bool Insert(string lastFirst, string first, string last, double batAVG, double slug, double oPS);
    bool Delete(string Key);
    void PrintOne(TreeNode *T);
    void PrintTree();
    void resetToStart();
    bool hasNext();
    Player getNext();
    bool add(string lastFirst, Player p);
    bool isFull();
    void clear();
    int  getSize();
    bool remove(Player p);
    void dump(ostream &);
    bool removePlayer(string key);
    void resetToEnd();
    bool hasPrev();
    Player getPrev();
    void PrintAllBackward(TreeNode *T);

    int   listLength;

    void PrintTreeBackward();

private:
    //private functions
    Node *pFirst;
    Node *pLast;
    Node *pCurrent;
    TreeNode *root;

    void ClearTree(TreeNode *T);
    TreeNode *DupNode(TreeNode * T);
    void PrintAll(TreeNode *T);

};