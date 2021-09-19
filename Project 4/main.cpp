/*Nathan Moore
 * CS 221 - Project 4 - take a list and implement a tree from it then print backwards
 */

#include <iostream>
#include <string>
#include "PlayerList.h"

using namespace std;

int main(void)
{
    PlayerList     myPlayers;   //creation of main function variables
    Player         player;
    TreeNode       *newNode;
    string in;
    string out;
    string dates, datesOut;
    ifstream inFile;        //creating instream variable
    ofstream outFile;       //creating outstream variable


    cout<<"Enter location of file including player data: ";  //prompt for user to enter input file location
    getline(cin, in);    //obtaining address by getting entire line
    cout<<"Enter location for desired output file for modified player data: ";   //prompt user to enter output file location
    getline(cin, out);   //obtaining address by getting entire line


    inFile.open(in);  //opening input file
    if (!inFile) {      //if the file doesn't open
        cout << "input file could not be opened please try again"; //prompt failure
        return 1;   //return an error code quit program
    } else {    //if success
        cout << "Reading data from input file" << endl; // prompt success continue program
    }

    outFile.open(out);  //opening output file
    if (!outFile) {     //if the file doesn't open
        cout << "output file could not be opened please try again"; //prompt failure
        return 2;   //return error code quit program
    } else {    //if success
        cout << "The new data has been written to the output file successfully." << endl << endl; //prompt success continue program
    }


    while (!inFile.eof()) {         //while file is open
        player.read(inFile);    //read from the file
        myPlayers.add(player.lastFirst, player);      //add objects read from file to list
    }

    myPlayers.resetToStart();
    while(myPlayers.hasNext()){
        player = myPlayers.getNext();
        player.computeStat();
    }

    myPlayers.resetToStart();       //reset list to beginning for initial outFile creation
    while(myPlayers.hasNext()) {     //iterate through list
        player = myPlayers.getNext();   //get the next in the list
        myPlayers.Insert(player.lastFirst, player.firstName, player.lastName, player.batAVG, player.slug, player.oPS);
    }


    // Print tree
    myPlayers.PrintTree();

    //print tree backwards
    myPlayers.PrintTreeBackward();

    //free all of tree and list
    myPlayers.resetToStart();       //reset list to beginning for initial outFile creation
    while(myPlayers.hasNext()) {     //iterate through list
        myPlayers.Delete(player.lastFirst);    // Delete a known leaf
        myPlayers.PrintTree();  //print tree after every removal for check
        myPlayers.remove(player);   //remove player currently on from list as well
    }

    return 0;   //end of code
}
