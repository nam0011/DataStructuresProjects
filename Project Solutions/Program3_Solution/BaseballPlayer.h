/* File: BaseballPlayer.h
   Program 3: Beth Allen
             
   The interface and structure definition of the BaseballPlayer class
   This version adds plate appearances, walks and hit by pitch to the statistics in a baseball player's data
   This version also adds the ability to compute the on base percentage and slugging percentage and includes
   these in the formatted form of the output.

   Program 3: Added compareByName to return an ordering (-1, 0, 1) of two players based on their names
*/

using namespace std;
#include <iostream>			// used for data streams
#include <string>			// I will use string class for simple situations

#define HITS_DATA_LENGTH 8   // i added 3 new values to the stats data

class BaseballPlayer {
	typedef enum { ATBATS, SINGLES, DOUBLES, TRIPLES, HOMERS, WALKS, HBP, APPEARANCES } mBattingIndex;    // I am using this to create a list of named values 0-4 for indexes


    string mLastName;					// last name of a baseball player, could also be used for sorting by name	
	string mFirstName;					// player's first name

	int  mHitting[HITS_DATA_LENGTH];	// an array to store the raw hitting stats for the player.
										// these stats include number of singles, doubles, etc.

	double mBattingAverage;				// batting average as computed from the statistics
	double mOnBasePercentage;			// on base percentage as a function of plate appearances
	double mSluggingPercentage;         // slugging percentage computation
	double mOPS;						// on base + slugging

public:
	BaseballPlayer();					// default constructor - sets all data to empty/default values

	void read(istream &input);			// read a player's stats from an input stream (file or keyboard)
	void computeStats();				// instructs the class object to compute its stats based on raw data

	// other interface methods required for get/set as needed
	string getFullName();
	string getFirstName();
	string getLastName();
	double getBattingAverage();
	double getOnBasePercentage();
	double getSluggingPercentage();
	double getOPS();
	int    compareByName(BaseballPlayer& otherPlayer);
	void   setName(string firstName, string lastName);

};