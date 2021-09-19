#include "PlayerList.h"
using namespace std;

//-----------------------------------------------------------------------------
// Node Constructor
//-----------------------------------------------------------------------------
Node::Node(const BaseballPlayer &P) {
	item = P;
	pNext = NULL;
	pPrev = NULL;
}

//***************************************************************************//
/* FILE: PlayerList.cpp   Version 3, doubly-linked list
   Class: PlayerList
   This is the implementation file for the methods defined in class
   PlayerList. Please see PlayerList.h for a description of the interface
*/

//---------------------------------------------------------------------------//
// Constructor: Default
// This constructor initializes a PlayerList to a pristine state.
// The index reflects the fact that the internal array is empty.
//---------------------------------------------------------------------------//	
PlayerList::PlayerList() {
	pCurrent = NULL;
	pFirst = NULL;
	mForwardIteration = true; 
	mPlayerCount=0;
}


//---------------------------------------------------------------------------//
// add(P) : takes the input player and copies it into the list
// This version of add is for sorted lists. It must be able to compare two
// players to determine their sort order. That means the Player class object
// has to define comparison logic to be used here.
//---------------------------------------------------------------------------//
bool PlayerList::add(BaseballPlayer &otherPlayer) {
	bool success = false;
	Node *pNew = new Node(otherPlayer);    // create a new node for this list.
	Node *p = NULL;              // temporary node. We are looking for the first node after the new Node's position
	Node *q = NULL;

	if (pNew == NULL) // we failed to allocate memory!
		return false;

	if (pFirst == NULL) // easy case - the list is empty so add our new node as the first node
	{
		pFirst = pNew;
	}
	else {
		q = NULL;
		p = pFirst;
		while (p && (otherPlayer.compareByName(p->item) > 0))  // as long as our new player is greater than p, keep moving p over
		{
			q = p;       // life is easiest if we have a trailer pointer
			p = p->pNext;
		}

		// HERE we have a spot for our new node  -  it could be the first node. We would check to see if p is the first node if it is, our node goes in front
		if (p == pFirst) {
			pNew->pNext = pFirst;
			pFirst->pPrev = pNew;
			pFirst = pNew;
		}
		else {
			// p comes after our new node
			pNew->pNext = p;
			pNew->pPrev = q;
			if (p) {
				p->pPrev = pNew;   // if our new node is NOT the last node, link back to it from p
			}
			if (q) {
				q->pNext = pNew;  // we also have to set pNew's prior node's link to point to new node
			}
		}  
	}	
	// count the new player
	mPlayerCount++;
	success = true;
	return success;
}
//---------------------------------------------------------------------------//
// remove()
// Given a playe object, this operation finds the matching player to remove
// from the list. It will return false if it could not find a player to remove
//----------------------------------------------------------------------------//
bool PlayerList::remove(BaseballPlayer &playerToFind) {
	bool found = false;
	Node *p;   // node to be removed
	Node *q;   // prior node to keep life easier

	p = pFirst;   // start at the beginning of the list
	while (p && !found)  // as long as I have a node and have not found the one I want
	{
		if (p->item.compareByName(playerToFind) == 0)  // if the  players are the same, p is the one I want
			found = true;
		else
			p = p->pNext;
	}

	if (found)   {  // then p points to the correct node to delete

		if (p == pFirst)   // we are removing the first node
		{
			pFirst = pFirst->pNext;
			if (pFirst) pFirst->pPrev = NULL;   // if there is a node, we need to set its back pointer to NULL if it is the new first node
		}
		else {  // there is at least 1 node before p
			q = p->pPrev;
			q->pNext = p->pNext;
			if (p->pNext)  p->pNext->pPrev = q;
		}
		delete p;
		mPlayerCount--;

	}		

	return found;
}

//---------------------------------------------------------------------------//
// resetIteration() - gets this list ready to begin an iteration through
// its data
// Pass in a flag, if true we are going to do forward iteration
// if false we are going to do backward iteration.  The default is true
//---------------------------------------------------------------------------//
void PlayerList::resetIteration(bool forwardFlag) {
	mForwardIteration = forwardFlag;
	if (mForwardIteration)
		pCurrent = pFirst;  // starts at front of array for data retrieval
	else { // find the end of the list
		pCurrent = pFirst;
		while (pCurrent && pCurrent->pNext) {    // while I am looking at a NODE and IF that node has a followon node, keep moving
			pCurrent = pCurrent->pNext;
		}
		// at this point pCurrent is set to the last node in the list for backward traversals
	}
}

//---------------------------------------------------------------------------//
// getNext()
// Returns a copy of next item in the iteration. If the list is at the end, 
// do not move the index over anymore
// Returns one baseball player object
//---------------------------------------------------------------------------//
BaseballPlayer PlayerList::getNext( ) {
	BaseballPlayer temp;
	if (pCurrent) // don't try to access a null pointer!
	{
		temp = pCurrent->item;  // copy the player out
		if (mForwardIteration)
			pCurrent = pCurrent->pNext;
		else
			pCurrent = pCurrent->pPrev;
	}
	return temp;
}

//---------------------------------------------------------------------------//
// hasNext()
// Returns true if there are more items in the list to be iterated through
//---------------------------------------------------------------------------//
bool PlayerList::hasNext()
{
	if (pCurrent ==  NULL)
		return false;
	else
		return true;
}

//---------------------------------------------------------------------------//
// clear() - sets the list to an empty state
//---------------------------------------------------------------------------//
void PlayerList::clear() {
	// This version needs to free all of the nodes in the list and then
	// set the status of attributes to reflect the list is empty
	Node *p;   // temporary node pointer
	
	while (pFirst) {
		p = pFirst->pNext;
		delete pFirst;			// delete memory for the current node
		pFirst = p;				// move to next node in list
	}
	mPlayerCount = 0;
	pFirst = NULL;
	pCurrent = NULL;
	mAverage = 0.0;
}

//--------------------------------------------------------------------------//
// getSize() - returns the count of players currently in this list
//---------------------------------------------------------------------------//
int  PlayerList::getSize() {
	return mPlayerCount;
}

//--------------------------------------------------------------------------//
// getAverage() - computes and returns the overall batting average for the
// players in the list
//---------------------------------------------------------------------------//
double PlayerList::getAverage() {
	Node* p = pFirst;     // used to iterate through players in a list an compute the overall batting average
	double sum = 0.0;
	while (p) {
		sum = sum + p->item.getBattingAverage();
		p = p->pNext;
	}
	if (mPlayerCount > 0) {
		mAverage = sum / mPlayerCount;
	}
	else {
		mAverage = 0.0;
	}
	return mAverage;
}

//---------------------------------------------------------------------------//
// isFull() - returns true if the list is at capacity, false otherwise 
//---------------------------------------------------------------------------//
bool PlayerList::isFull() {
	return false;
}

//---------------------------------------------------------------------------//
// isEmpty() - returns true if the list is empty, false otherwise 
//---------------------------------------------------------------------------//
bool PlayerList::isEmpty() {
	
	return (pFirst == NULL);
}