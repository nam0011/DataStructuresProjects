/* File: Program1.cpp
   BETH ALLEN
   CS221 Fall 2020
   This program test drives the BaseballPlayer class.  It will be used to read data to and from the screen and
   test the computation of the batting average statistics.

   The general operation of this program is to allow the user to enter one baseball player at a time and output that player to the
   screen until they wish to quit the program.  The only methods implemented so far are those needed
   to complete the first programming assignment.
   
   This program was tested in Visual Studio 2019

 */

using namespace std;
#include <iostream>			
#include <iomanip>

#include "BaseballPlayer.h"			// include the declaration of the baseball player class

//-----------------------------------------------------------------------------------------------//
// Main program
// Uses a single variable to store a player. The loop reuses the variable over and over until
// the user wants to quit.
//-----------------------------------------------------------------------------------------------//

int main(void) {

	BaseballPlayer  aPlayer;			// a single baseball player
	char			response;			// used to read y/n response from user
	
	cout << "Welcome to the baseball player statistics test driver program.\n";
	cout << "When prompted, please enter the player's data in the form of \n";
	cout << "firstname lastname plateapps atbats singles doubles triples homeruns bbs hbp.\n";
	cout << "For example:\n\n";
	cout << "Chipper Jones 10614 8984 1671 549 38 468 1512 18\n\n";

	response = 'Y';
	while (toupper(response) == 'Y') {

		cout << "\nEnter Player Data: ";
		aPlayer.read(cin);
		aPlayer.computeStats();
		
		cout << std::fixed << "    " << aPlayer.getFullName() << "'s Batting Average = ";
		cout << setw(6) << setprecision(3) << aPlayer.getBattingAverage();
		cout << " and OBP = " << setw(6) << setprecision(3) << aPlayer.getOBP() << endl;

		cout << "\nDo you wish to test another [y/n]? ";
		cin >> response;

	} // end while loop.

	cout << "\n\nProgram 1 Testing Complete\n";

	return 0;
}