#pragma once
#include <string>
#include "BaseballPlayer.h"
using namespace std;
//***************************************************************************//
/* FILE: PlayerList.h    Version Doubly Linked List (Program 3 Assignment)
   Class: PlayerList
   This class uses a doubly-linked list to maintain a list of baseball players.
   
   Public Methods:
        PlayerList - default constructor
        add     	- add a player to the list
		remove      - removes a player by name match from this list
		resetIteration - to start at the beginning of the list array
		getNext     - get a copy of the next player in the list
		hasNext     - true/false if there is another player to get
		clear		- initialize the list to a clean state
		getSize     - gets the count of items in the list
		isEmpty	    - test to see if the list is empty
		isFull      - test to see if list is full

*/

class PlayerList;   // forward reference to define the name of our future data type so Node can refer to it
class Node {
	BaseballPlayer item;	    // the player data stored in this node
	Node *pNext;	        // the next node in the linked list
	Node *pPrev;		    // the previous node in the linked list
	Node(const BaseballPlayer &P);        // node constructor
	friend PlayerList;      // PlayerList can see the private fields of its own Nodes.
};

class PlayerList {
	int      mPlayerCount;			// number of items stored in the list
	double   mAverage;				// overall team average
	Node    *pFirst;                // the first node in the linked list, I am not using last because in a sorted list it doesn't really matter who is last
	Node    *pCurrent;              // used in iterations for pointing to the next node
	bool     mForwardIteration;     // used for directional iterations.
public:
	PlayerList();
	bool	 add(BaseballPlayer &);
	bool     remove(BaseballPlayer &);
	void	 resetIteration(bool f=true);  // NEW VERSION will set forward or backward iteration
	BaseballPlayer getNext();
	bool	 hasNext();

	void	 clear();
	int		 getSize();
	bool	 isEmpty();     
	bool	 isFull();     // no longer has any meaning with dynamic allocation

	double   getAverage();
};
	