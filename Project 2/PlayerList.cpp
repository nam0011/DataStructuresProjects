/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  PlayerList.cpp defines public and private class functions used by end user to manipulate a list of Player objects
 */


#include "PlayerList.h"
using namespace std;


Node::Node(const Player& playerIn){ //default Node constructor
    item = playerIn;
    pNext = NULL;       //setting next to NULL by default
    pPrev = NULL;
}


PlayerList::PlayerList(){  //default PlayerList constructor
    listLength = 0;     //set list length to 0 as default since it stores no values when first set
    pFirst = NULL;      //no nodes in list
    pPrev = NULL;
    pCurrent = NULL;

}

bool PlayerList::isEmpty(){    //function returns true if list is empty
    return pFirst == NULL;
}

bool PlayerList::isFull(){  //function returns true is the list is full - this will never happen as we are not currently setting a max to the list
    return false;
}


bool PlayerList::add(Player p){     //function to add a player to the list

    Node* pNew; // pointer to new node
    pNew = new Node(p); //creation of new node

    if (isEmpty()) {
        pFirst = pNew;  //if list is empty we must be adding to the first space in our list
    }
    else {
        pLast->pNext = pNew;    //if list is not empty we are adding onto the end of the list
        pPrev = pCurrent;
    }
    pLast = pNew;   //new node is also end of the list - ensures the next node adds on after this one
    listLength++;   //iterate the list to count for the added team member

    if (pNew == NULL){ //failure, need flag to signal hanging pointer/memory leak
        return false;
    }
    return true;
}

bool PlayerList::remove(Player player){     //function to remove a player from the list
    bool found = false; //default to false because we want to trigger true if a match is found

    Node* p;    //node to retrieve and remove
    Node* q;    //node that stores where p previously was allowing p to move through list without destroying it

    p = pFirst;
    q = NULL;
    found = false;


    while (p != NULL && (!p->item.equals(player))){ //as long as a node exists and it is not what we are looking for allows for p and q to move along list
        q = p;    // saves current position
        p = p->pNext;    // moves p to the next node
    }


    if (p != NULL){ //p cannot be a null pointer it must be able to unlink to iterate
        if (p->pNext == NULL){  //p is at end of list
            pLast = q;  //deleting the last node
            if (pLast) {
                pLast->pNext = NULL; //shows where the end of the list is now after removal
            }
        }

        if (q == NULL){
            pFirst = p->pNext;  // if node in front of q is empty this means the first node is being removed
        }
        else{   //if p is not the first node then
            q->pNext = p->pNext;    // q must be rerouted to the node before p so p can be rerouted to the one after itself
        }
        found = true;
        delete p;      //free p nodes memory
        listLength--;   //decrement list length counter so that it reflects list length correctly
    }
    return found;
}

int PlayerList::getSize(){  //returns size of the list created
    return listLength;
}

void PlayerList::resetToStart(){    //resets list to the beginning for reiteration
    pCurrent = pFirst;
}

bool PlayerList::hasNext() {    //checks to see if there is another object to retrieve
    return pCurrent != NULL;
}

Player PlayerList::getNext() {  //function to get next available object
    Player item;        //creates player object named item to store objects
    if (pCurrent != NULL) { //makes sure no bad data is accessed
        item = pCurrent->item;  //copies object from pointer into item
        pCurrent = pCurrent->pNext; //move to the next node in linked list to get next object
    }
    return item;
}


void PlayerList::clear(){   //clears memory used by program
    Node* p;    //pointer to be cleared
    while (pFirst != NULL)
    {
        p = pFirst;     //save address of first node
        pFirst = pFirst->pNext; //move to next node
        delete p;   //delete the first node
    }

    pLast = NULL;   //ensures that pfirst is also plast and is NULL
    listLength = 0; //emptys list length back to default value
}


PlayerList::~PlayerList() { //uses clear function - Default Destructor
    clear();
}

void PlayerList::dump(ostream& o){   //dumps list to output

    Node* p;
    p = pFirst;
    while (p) {
        p->item.print(o);  // prints to output
        o << endl;
        p = p->pNext;	   // move to next node
    }
}

