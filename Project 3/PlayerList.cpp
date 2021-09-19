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
    pPrev = NULL;       //setting previous to NULL by default
    string key = "";
}


PlayerList::PlayerList(){  //default PlayerList constructor
    listLength = 0;     //set list length to 0 as default since it stores no values when first set
    pFirst = NULL;      //no nodes in list
    pCurrent = NULL;
    pLast = NULL;

}

bool PlayerList::isEmpty(){    //function returns true if list is empty
    return pFirst == NULL;
}

bool PlayerList::isFull(){  //function returns true is the list is full - this will never happen as we are not currently setting a max to the list
    return false;
}


bool PlayerList::add(string lastFirst, Player p){     //function to add a player to the list
    Node* pNew; // pointer to new node
    Node* temp;

    pNew = new Node(p); //creation of new node

    pNew->pNext = NULL; //setting pointer to next node to null
    pNew->pPrev = NULL; //setting pointer to prev node to null

    pNew->key = lastFirst;

    if (isEmpty()) {
        pFirst = pNew;  //if list is empty we must be adding to the first space in our list
        cout<<pNew->key<<" is first in list"<<endl;
    }

    else {
        temp = pFirst;

       while((temp->pNext != NULL && (temp->key < lastFirst ))) { //find location for new node
           temp = temp->pNext;     //iterating through list ->
          cout<<temp->key<<" moved to next slot "<<endl;
       }
       if ((temp->pNext == NULL) && ((pNew->key > temp->key))) {  //adding at the end of the list
           temp->pNext = pNew;     //make the last node the incoming node  ->
           pNew->pPrev = temp;     //tie the node prior the incoming node to the incoming node <-
           cout<<temp->key<<" add to end "<<endl;

       }
       else {
           pNew->pPrev = temp->pPrev;  //adding new node sorted into middle of list        // interchanging the previous node to disconnect from temp and connect to pNew  <-
           pNew->pNext = temp;     //temp is now the node after pNew ->
           temp->pPrev->pNext = pNew;  //original pPrev now tied to pNext as next node ->
           temp->pPrev = pNew; //temp now tied to pNew both ways <-
           cout<<temp->key<<" add in between "<<endl;
       }

    }
    listLength++;   //iterate the list to count for the added team member

    if (pNew == NULL){ //failure, need flag to signal hanging pointer/memory leak
    return false;
    }
    return true;    //confirms that a node was created
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

bool PlayerList::removePlayer(string key){

    Node* temp, * prev;
    temp = pFirst;
    prev = NULL;

    while (temp != NULL && temp->key != key)   //if its the first one, we need to move the m_first pointer first, then delete the first element.
    {
        prev = temp;
        temp = temp->pNext;
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        if (prev == NULL)   //unlink the current temp Node.
        {
            // this means temp is first;
            pFirst = temp->pNext;
        }
        else
        {
            //we are somewhere else
            prev->pNext = temp->pNext;
        }

        if (temp == pLast)
        {
            pFirst = prev;
        }

        delete temp;
        listLength--;
        return true;
    }
}

void PlayerList::resetToEnd(){  //set current iterator to last of list
    pCurrent = pLast;
}

bool PlayerList::hasPrev(){ //if pCurrent is not null then must have a previous
    return pCurrent != NULL;
}

Player PlayerList::getPrev(){   //iterate backwards through list
    Player item;    //item to iterate and return
    if (pCurrent != NULL){
        item = pCurrent->item; //set player item to that held in current node
        pCurrent = pCurrent->pPrev; //move the node to the next node
    }
    return item;
}