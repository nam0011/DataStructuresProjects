/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  PlayerList.cpp defines public and private class functions used by end user to manipulate a list of Player objects
 */

#include "PlayerList.h"
using namespace std;

PlayerList::PlayerList(){  //default PlayerList constructor
    listLength = 0;     //set list length to 0 as default since it stores no values when first set
    listCur= 0;
}

bool PlayerList::isEmpty(){    //function returns true if list is empty
    return listLength == 0;
}

bool PlayerList::isFull(){  //function returns true is the list is full - this will never happen as we are not currently setting a max to the list
    return listLength >= MAXSIZE;
}


bool PlayerList::add(Player p){     //function to add a player to the list


    bool success = false;  // flag to represent success or not
    if (listLength < MAXSIZE) // if there is capacity, copy the date in
    {
        items[listLength] = p;
        listLength++;
        success = true;
    }
    else
        success = false;

    return success;
}

bool PlayerList::remove(const Player &p){     //function to remove a player from the list

    bool found = false; //default to false because we want to trigger true if a match is found
    int  index = 0;    // index of the matching date in the list


    while (!found  && index < listLength) // if we have a valid index
    {
        if (items[index].equals(p))
            found = true;    // stop the loop here at this index
        else
            index++;
    }
    if (found) {
        listLength--;
        items[index] = items[listLength];  // move end item into this spot
    }
    return found;
}



int PlayerList::getSize(){  //returns size of the list created
    return listLength;
}



void PlayerList::resetToStart(){    //resets list to the beginning for reiteration
    listCur = 0;
}



bool PlayerList::hasNext() {    //checks to see if there is another object to retrieve
    if (listCur < listLength)
        return true;
    else
        return false;  // no more data to visit
}



Player PlayerList::getNext() {  //function to get next available object
    Player item;        //creates player object named item to store objects
  
    if (listCur < listLength) {       // this will keep current from going too far
        item = items[listCur];	  // but it is still possible for user to attempt more accesses
        listCur++;
    }
    return item;  // return a copy of the item retrieved from list
}


void PlayerList::clear(){   //clears memory used by program
    listLength = 0; //emptys list length back to default value
}


PlayerList::~PlayerList() { //uses clear function - Default Destructor
    clear();
}



/*******************************************
* NEEDS EDITING BUT WILL WORK SOON
********************************************/
void PlayerList::sortBatAVG() {
    Player* temp = new Player[listLength];
    mergeSort(items, 0, listLength - 1, temp);
    delete[]temp;
}

void PlayerList::mergeSort(Player items[], int first, int last, Player temp[]){
    int middle; // middle index used to divide array in half
    if (first < last) {
        middle = (first + last) / 2; // array has at least 2 items to be sorted
        mergeSort(items, first, middle, temp); // sort left half
        mergeSort(items, middle + 1, last, temp);// sort right half
        merge(items, first, middle, middle + 1, last, temp);  // merge two halves
    }
}

void PlayerList::merge(Player items[], int first, int last1, int second, int last2, Player temp[]){
    int i = first, j = second, k = 0;

    while (i <= last1 && j <= last2)
    {
        if (items[i].batAVG >= items[j].batAVG){
            temp[k] = items[i];
            k++;
            i++;
        }
        else{
            temp[k] = items[j];
            k++;
            j++;
        }
    }

    while (i <= last1){

        temp[k] = items[i];
        k++;
        i++;
    }
    while (j <= last2){
        temp[k] = items[j];
        k++;
        j++;
    }
    for (i = 0; i < k; i++){
        items[first + i] = temp[i];
    }
}