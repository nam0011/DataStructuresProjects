#include <iostream>
#include <cstring>
#include "PlayerList.h"

using namespace std;



Node::Node(const Player& playerIn){ //default Node constructor
    item = playerIn;
    pNext = NULL;       //setting next to NULL by default
    pPrev = NULL;       //setting previous to NULL by default
    string key = "";
}


//--------------------------------------------
// Function: PlayerList()
// Purpose: Class constructor.
//--------------------------------------------
PlayerList::PlayerList()
{
    root = NULL;
    listLength = 0;     //set list length to 0 as default since it stores no values when first set
    pFirst = NULL;      //no nodes in list
    pCurrent = NULL;
    pLast = NULL;
}

//--------------------------------------------
// Function: PlayerList()
// Purpose: Class destructor.
//--------------------------------------------
PlayerList::~PlayerList()
{
    ClearTree(root);
    return;
}

//--------------------------------------------
// Function: ClearTree()
// Purpose: Perform a recursive traversal of
//        a tree destroying all nodes.
//--------------------------------------------
void PlayerList::ClearTree(TreeNode *T)
{
    if(T==NULL) return;  // Nothing to clear
    if(T->left != NULL) ClearTree(T->left); // Clear left sub-tree
    if(T->right != NULL) ClearTree(T->right); // Clear right sub-tree
    delete T;    // Destroy this node
    return;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return TRUE if tree is empty.
//--------------------------------------------
bool PlayerList::isEmpty()
{
    return(root==NULL);
}

//--------------------------------------------
// Function: DupNode()
// Purpose: Duplicate a node in the tree.  This
//        is used to allow returning a complete
//        structure from the tree without giving
//        access into the tree through the pointers.
// Preconditions: None
// Returns: Pointer to a duplicate of the node arg
//--------------------------------------------
TreeNode *PlayerList::DupNode(TreeNode * T)
{
    TreeNode *dupNode;

    dupNode = new TreeNode();
    *dupNode = *T;    // Copy the data structure
    dupNode->left = NULL;    // Set the pointers to NULL
    dupNode->right = NULL;
    return dupNode;
}

//--------------------------------------------
// Function: SearchTree()
// Purpose: Perform an iterative search of the tree and
//        return a pointer to a treenode containing the
//        search key or NULL if not found.
// Preconditions: None
// Returns: Pointer to a duplicate of the node found
//--------------------------------------------
TreeNode *PlayerList::SearchTree(string Key)
{
    int      ValueInTree = false;
    TreeNode *temp;

    temp = root;
    while((temp != NULL) && (temp->Key != Key))
    {
        if(Key < temp->Key)
            temp = temp->left;  // Search key comes before this node.
        else
            temp = temp->right; // Search key comes after this node
    }
    if(temp == NULL) return temp;    // Search key not found
    else
        return(DupNode(temp));    // Found it so return a duplicate
}

//--------------------------------------------
// Function: Insert()
// Insert a new node into the tree.
// Preconditions: None
// Returns: int (TRUE if successful, FALSE otherwise)
//--------------------------------------------
bool PlayerList::Insert(TreeNode *newNode)
{
    TreeNode *temp;
    TreeNode *back;

    temp = root;
    back = NULL;

    while(temp != NULL) // Loop till temp falls out of the tree
    {
        back = temp;
        if(newNode->Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }

    // Now attach the new node to the node that back points to
    if(back == NULL) // Attach as root node in a new tree
        root = newNode;
    else
    {
        if(newNode->Key < back->Key)
            back->left = newNode;
        else
            back->right = newNode;
    }
    return true ;
}

//--------------------------------------------
// Function: Insert()
// Insert a new node into the tree.
// Preconditions: None
// Returns: int (TRUE if successful, FALSE otherwise)
//--------------------------------------------
bool PlayerList::Insert(string lastFirst, string first, string last, double batAVG, double slug, double oPS)
{
    TreeNode *newNode;

    // Create the new node and copy data into it
    newNode = new TreeNode();
    newNode->Key = lastFirst;
    newNode->first = first;
    newNode->last = last;
    newNode->batAVG = batAVG;
    newNode->slug = slug;
    newNode->oPS = oPS;

    newNode->left = newNode->right = NULL;

    // Call other Insert() to do the actual insertion
    return(Insert(newNode));
}

//--------------------------------------------
// Function: Delete()
// Purpose: Delete a node from the tree.
// Preconditions: Tree contains the node to delete
// Returns: int (TRUE if successful, FALSE otherwise)
//--------------------------------------------
bool PlayerList::Delete(string Key)
{
    TreeNode *back;
    TreeNode *temp;
    TreeNode *delParent;    // Parent of node to delete
    TreeNode *delNode;      // Node to delete

    temp = root;
    back = NULL;

    // Find the node to delete
    while((temp != NULL) && (Key != temp->Key))
    {
        back = temp;
        if(Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == NULL) // Didn't find the one to delete
    {
        return false;
    }
    else
    {
        if(temp == root) // Deleting the root
        {
            delNode = root;
            delParent = NULL;
        }
        else
        {
            delNode = temp;
            delParent = back;
        }
    }

    // Case 1: Deleting node with no children or one child
    if(delNode->right == NULL)
    {
        if(delParent == NULL)    // If deleting the root
        {
            root = delNode->left;
            delete delNode;
            return true;
        }
        else
        {
            if(delParent->left == delNode)
                delParent->left = delNode->left;
            else
                delParent->right = delNode->left;
            delete delNode;
            return true;
        }
    }
    else // There is at least one child
    {
        if(delNode->left == NULL)    // Only 1 child and it is on the right
        {
            if(delParent == NULL)    // If deleting the root
            {
                root = delNode->right;
                delete delNode;
                return true;
            }
            else
            {
                if(delParent->left == delNode)
                    delParent->left = delNode->right;
                else
                    delParent->right = delNode->right;
                delete delNode;
                return true;
            }
        }
        else // Case 2: Deleting node with two children
        {
            // Find the replacement value.  Locate the node
            // containing the largest value smaller than the
            // key of the node being deleted.
            temp = delNode->left;
            back = delNode;
            while(temp->right != NULL)
            {
                back = temp;
                temp = temp->right;
            }
            // Copy the replacement values into the node to be deleted
            delNode->Key = temp->Key;
            delNode->last = temp->last;
            delNode->first = temp->first;
            delNode->batAVG = temp->batAVG;
            delNode->slug = temp->slug;
            delNode->oPS = temp->oPS;

            // Remove the replacement node from the tree
            if(back == delNode)
                back->left = temp->left;
            else
                back->right = temp->left;
            delete temp;
            return true;
        }
    }
}

//--------------------------------------------
// Function: PrintOne()
// Purpose: Print data in one node of a tree.
// Preconditions: None
// Returns: void
//--------------------------------------------
void PlayerList::PrintOne(TreeNode *T)
{
    cout <<T->first << " " << T->last << " "<< T->batAVG << " "<< T->batAVG<< " "<< T->slug<<" "<<T->oPS<< "\n";
}

//--------------------------------------------
// Function: PrintAll()
// Purpose: Print the tree using a recursive
//        traversal
// Preconditions: None
// Returns: void
//--------------------------------------------
void PlayerList::PrintAll(TreeNode *T)
{
    if(T != NULL)
    {
        PrintAll(T->left);
        PrintOne(T);
        PrintAll(T->right);
    }
}

void PlayerList::PrintAllBackward(TreeNode *T)
{
    PrintAll(T->left);
    PrintAll(T->right);
    PrintOne(T);
}



void PlayerList::PrintTree()
{
    PrintAll(root);
}

void PlayerList::PrintTreeBackward()
{
    PrintAllBackward(root);
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