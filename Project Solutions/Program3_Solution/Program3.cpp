/* File: Program3.cpp
   BETH ALLEN
   
   This program test drives the Quarterback class.  This version is using a doubly linked
   list to store each player in a node.

   It was not required on the assignment, but I am going to print the list out backward to make
   sure  my back links are working appropriately.

   This program reads the quarterback player data from the input file in the same manner as 
   program 2. It stores the qbs in a double-linked list structure, with the additional requirement that
   they are placed in order by name.  

   Also, the list supports a remove operation that is also tested in the program.

 */

using namespace std;
#include <iostream>	
#include <fstream>
#include <iomanip>

#include "PlayerList.h"


// utilities for main program report printing
// print a line of data based on a player
//-----------------------------------------------------------------------------------------------//
void printReportLine(ostream& out, BaseballPlayer& p1) {
	out << std::fixed << std::setprecision(3);
	out << setw(20) << p1.getLastName() + ", " + p1.getFirstName();
	out << " :    " << setw(6) << setprecision(3) << p1.getBattingAverage();
	out << "   " << setw(6) << setprecision(3) << p1.getOPS();
	out << endl;
}

//-----------------------------------------------------------------------------------------------//
// Main program
// Uses a single variable to store a player temporarily until it is added to the list.
// The loop reuses the variable over and over until all lines of the input file have been 
// retrieved.
//-----------------------------------------------------------------------------------------------//

int main(void) {
	char   inFileName[100];
	char   outFileName[100];				// names of the input and output data files supplied by the user
	ifstream inputFile;						// input file handle
	ofstream outputFile;					// output file handle
	BaseballPlayer aPlayer;					// a temporary  object = the current player being read or printed
	PlayerList   myTeam;					// the list storage
	char      response;						// used for testing the remove operations
	char      gobble;						// "
	string    first, last;					// "
	
	cout << "Welcome to the player statistics calculator test program.  I am going to\n";
	cout << "read players from an input data file.  You will tell me the names of\n";
	cout << "your input and output files.  I will store all of the players in a list, \n";
	cout << "compute each player's stats and then write the resulting report \n";
	cout << "to your output file.\n\n";

	cout << "\n\n";

	
	cout << "Enter the name of your input file:  ";  cin >> inFileName;
	cout << "Enter the name of your output file: ";  cin >> outFileName;
	cin.get(gobble);  // gobble up eoln character

	// opening data files
	inputFile.open(inFileName);
	if (inputFile.fail()) { 
		cout << "Sorry. I could not open your input file - " << inFileName << "-\n";
		cout << "Exiting the program.\n";  return 1;
	}
	outputFile.open(outFileName);
	if (outputFile.fail()) { 
		cout << "Sorry. I could not open your output file - " << outFileName << "-\n";
		cout << "Exiting the program.\n";  return 1;
	}

	cout << "Reading Players from " << inFileName << endl;
	
	while (!inputFile.eof()) {
		aPlayer.read(inputFile);
		aPlayer.computeStats();
		myTeam.add(aPlayer);   // add this player to the list - NOTE THIS NEW version adds in order by name
	}

	outputFile << "BASEBALL TEAM REPORT --- " << myTeam.getSize() << " PLAYERS FOUND IN FILE\n";
	outputFile << "OVERALL BATTING AVERAGE is " << std::fixed << std::setprecision(3) << myTeam.getAverage();
	outputFile << endl << endl;

	outputFile << "    PLAYER NAME      :    AVERAGE    OPS\n";
	outputFile << "----------------------------------------------\n";
	
	myTeam.resetIteration(); // get ready to visit each student - go forward
	while (myTeam.hasNext()) {
		aPlayer = myTeam.getNext();  // get next player
		printReportLine(outputFile, aPlayer);
	}


	cout << "The sorted list has been written to your output file: " << outFileName << endl;

	cout << "\nWould you like to remove any players from your list? ";
	cin.get(response);
	cin.get(gobble);
	while (response == 'Y' || response == 'y') {
		cout << "    Please enter the First and Last Name of the Player: ";
		cin >> first >> last;
		cin.get(gobble);
		aPlayer.setName(first, last);   // use a temporary player object with just a name for comparisons
		if (myTeam.remove(aPlayer))
			cout << "    " << first << " " << last << " Removed Successfully.\n";
		else
			cout << "    " << first << " " << last << " was not found in your list.\n";
		cout << endl;
		cout << "Would you like to remove any players from your list? ";
		cin.get(response);
		cin.get(gobble);
	}

	outputFile << "\n\nThe list after removals contains " << myTeam.getSize() << " entries\n";
	outputFile << "They are: \n";

	myTeam.resetIteration(); // get ready to visit each player - go forward
	while (myTeam.hasNext()) {
		aPlayer = myTeam.getNext();
		printReportLine(outputFile, aPlayer);
	}

	cout << "Testing Complete. The new version of your list has been added to\n";
	cout << "the report file.\n\n";

	
	inputFile.close();
	outputFile.close();

	cout << "\n\n";
	cout << "For testing purposes, here is the list in reverse order:\n";
	myTeam.resetIteration(false); // get ready to visit each student - go backwards
	while (myTeam.hasNext()) {
		aPlayer = myTeam.getNext();
		printReportLine(cout, aPlayer);  // print to screen
	}


	cout << "\n\n";
	cout << "End of Program 3\n";

	return 0;
}