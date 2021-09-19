NameList::PlayerList(){
    counter = 0;
    for(int i = 0; i<100, i++){
        items[i]= 0;
    }

}

bool NameList::add(Name n){     //function to add a player to the list
    Node* pNew; // pointer to new node
    pNew = new Node(n); //creation of new node

    if (isEmpty()) {
        pFirst = pNew;  //if list is empty we must be adding to the first space in our list
    }
    else {
        pLast->pNext = pNew;    //if list is not empty we are adding onto the end of the list
    }
    pLast = pNew;   //new node is also end of the list - ensures the next node adds on after this one
    listLength++;   //iterate the list to count for the added team member

    if (pNew == NULL){ //failure, need flag to signal hanging pointer/memory leak
        return false;
    }
    return true;
}

bool NameList::remove(Name n){     //function to remove a player from the list
    bool found = false; //default to false because we want to trigger true if a match is found

    Node* p;    //node to retrieve and remove
    Node* q;    //node that stores where p previously was allowing p to move through list without destroying it

    p = pFirst;
    q = NULL;
    found = false;


    while (p != NULL && (!p->item.equals(n))){ //as long as a node exists and it is not what we are looking for allows for p and q to move along list
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

