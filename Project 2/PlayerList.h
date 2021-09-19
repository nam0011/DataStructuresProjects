/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  PlayerList.h defines public and private class functions used by PlayerList.cpp and any other further inherited files
 */
#include "Player.h" //inheriting all of Player classes public functions, variables, and libraries
using namespace std;    //using namespace std unless otherwise defined

class Node {    //creation of class Node

public: //public variables and functions
    Player item;
    Node *pNext;
    Node *pPrev;
    Node(const Player &playerIn);

};


class PlayerList {

public:
    //public functions
    PlayerList();
    ~PlayerList();
    bool isEmpty();
    bool isFull();
    void clear();
    bool add(Player p);
    int  getSize();
    void resetToStart();
    bool hasNext();
    Player getNext();
    bool remove(Player p);
    void dump(ostream &);

    //public variables
    int   listLength;

private:
    //private functions
    Node *pFirst;
    Node *pLast;
    Node *pPrev;
    Node *pCurrent;
};
