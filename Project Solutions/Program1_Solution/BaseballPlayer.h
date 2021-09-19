/* File: BaseballPlayer.h
   Program 1: Beth Allen
              Fall 2020
   The interface and structure definition of the BaseballPlayer class
*/

using namespace std;
#include <iostream>			// used for data streams
#include <string>			// I will use string class for simple situations

#define STATS_DATA_LENGTH 8  // how many numeric stats are in the array

class BaseballPlayer {
	typedef enum { PAS, ATBATS, SINGLES, DOUBLES, TRIPLES, HRS, BB, HBP} mBattingIndex;    // I am using this to create a list of named values 0-7 for indexes

    string mLastName;					// last name of a baseball player, could also be used for sorting by name	
	string mFirstName;					// player's first name
	int  mHitting[STATS_DATA_LENGTH];	// an array to store the raw hitting stats for the player.
										// these stats include number of singles, doubles, etc.
	double mBattingAverage;				// batting average as computed from the statistics
	double mOnBasePercentage;           // OBP

public:
	BaseballPlayer();					// default constructor - sets all data to empty/default values
	void read(istream &input);			// read a player's stats from an input stream (file or keyboard)
	void computeStats();				// instructs the class object to compute its stats based on raw data

	// other interface methods required for get/set as needed
	string getFullName();
	double getBattingAverage();
	double getOBP();
};