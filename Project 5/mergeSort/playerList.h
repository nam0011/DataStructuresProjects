/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  PlayerList.h defines public and private class functions used by PlayerList.cpp and any other further inherited files
 */
#include "Player.h" //inheriting all of Player classes public functions, variables, and libraries
using namespace std;    //using namespace std unless otherwise defined

#define MAXSIZE 100

class PlayerList {

public:
    //public functions
    PlayerList();
    ~PlayerList();
    void sortBatAVG();
    void mergeSort(Player items[], int first, int last, Player temp[]);
    void merge(Player items[], int first, int last1, int second, int last2, Player temp[]);
    bool isEmpty();
    bool isFull();
    void clear();
    bool add(Player p);
    int  getSize();
    void resetToStart();
    bool hasNext();
    Player getNext();
    bool remove(const Player &p);
    void dump(ostream &);

    //public variables
    int   listLength;
    Player   items[MAXSIZE];
    int   listCur;

};
