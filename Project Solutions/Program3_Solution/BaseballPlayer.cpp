/* File: BaseballPlayer.cpp
   Program 3: Beth Allen
              
   Implementation of the class BaseballPlayer - VERSION 2. See the .h file for more
   descriptions of the member attributes and functions.
   All of the methods are contained in this file.

    Program 3: Added compareByName to return an ordering (-1, 0, 1) of two players based on their names
*/
#include "BaseballPlayer.h"
#include <string.h>

//-----------------------------------------------------------------------------------------------//
// Default Constructor
// Sets numberic values to zeros, and other values to either empty strings or default values
//-----------------------------------------------------------------------------------------------//
BaseballPlayer::BaseballPlayer() {

	mFirstName = "unknown";
	mLastName = "unknown";
	for (int i = 0; i <= APPEARANCES; i++)
		mHitting[i] = 0;

}

//-----------------------------------------------------------------------------------------------//
// read(input)
// VERSION 2:  reads in plate apperances before the hits data, and the walks and HBP
//
// This method reads the baseball player's data from a single line on an input stream.
// Some special restrictions - the player's first name and last name can each only consist of
// a single word (no embedded spaces), other wise the input will be read in incorrectly.
// There must also be all 5 statistics data values on the line.
// The order of input is firstname lastname appearances atbats singles doubles triples homeruns walks hbp
//
// Parameters:
//    input   : a variable representing the input stream to read data from
//-----------------------------------------------------------------------------------------------//
void BaseballPlayer::read(istream &input) {

	input >> mFirstName >> mLastName;
	input >> mHitting[APPEARANCES];   // i am storing the first value at the end of my data array
	for (int i = ATBATS; i <= HBP; i++)
		input >> mHitting[i];				// read in each stat from input stream

}


//-----------------------------------------------------------------------------------------------//
// computeStats
// This function currently computes the player's batting average based on the hitting data.
// Later revisions will compute additional player statistics.
//-----------------------------------------------------------------------------------------------//
void BaseballPlayer::computeStats()  {
	mBattingAverage = 0.0;
	mSluggingPercentage = 0.0;

	for (int i = SINGLES; i <= HOMERS; i++)   {// step through the hitting values and sum them
		mBattingAverage = mBattingAverage + mHitting[i];
		mSluggingPercentage = mSluggingPercentage + (i * mHitting[i]);
	}
	if (mHitting[ATBATS] > 0) {
		mBattingAverage = mBattingAverage / mHitting[ATBATS];
		mSluggingPercentage = mSluggingPercentage / mHitting[ATBATS];
	}
	else {
		mBattingAverage = 0.0;		// if there was a 0 in the at bats, we can't divide by it
		mSluggingPercentage = 0.0;
	}

	// compute on base percentage too
	mOnBasePercentage = 0.0;
	for (int i = SINGLES; i <= HBP; i++) {
		mOnBasePercentage = mOnBasePercentage + mHitting[i];
	}
	if (mHitting[APPEARANCES] > 0)
		mOnBasePercentage = mOnBasePercentage / mHitting[APPEARANCES];
	else
		mOnBasePercentage = 0.0;

	mOPS = mOnBasePercentage + mSluggingPercentage;
}



//-----------------------------------------------------------------------------------------------//
// getFullName()
// This get method is used to get the player's full name built as a single string from the
// names stored in the class.
//-----------------------------------------------------------------------------------------------//
string BaseballPlayer::getFullName() {
	return mFirstName + " " + mLastName;
}
//-----------------------------------------------------------------------------------------------//
// getFirstName()
// This get method is used to get the player's first name
//-----------------------------------------------------------------------------------------------//
string BaseballPlayer::getFirstName() {
	return mFirstName;
}
//-----------------------------------------------------------------------------------------------//
// getLastName()
// This get method is used to get the player's last name 
//-----------------------------------------------------------------------------------------------//
string BaseballPlayer::getLastName() {
	return mLastName;
}

//-----------------------------------------------------------------------------------------------//
// getBattingAverage()
// Used to retrieve the batting average for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getBattingAverage() {
	return mBattingAverage;
}
//-----------------------------------------------------------------------------------------------//
// getSluggingPercentage()
// Used to retrieve the slugging average for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getSluggingPercentage() {
	return mSluggingPercentage;
}
//-----------------------------------------------------------------------------------------------//
// getOnBasePercentage()
// Used to retrieve the on base average for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getOnBasePercentage() {
	return mOnBasePercentage;
}
//-----------------------------------------------------------------------------------------------//
// getOPS()
// Used to retrieve the OPS for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getOPS() {
	return mOPS;
}

//-----------------------------------------------------------------------------------------------//
// compareByName
// uses the full name to do  a comparison for sort order
// returns -1 0 1 to reflect < = >
//-----------------------------------------------------------------------------------------------//
/*int BaseballPlayer::compareByName(BaseballPlayer& otherPlayer) {
	// _stricmp is a utility to do string comparisons, case insensitive
    // .c_str() is a utility to pull out the character array of a string variable to use with
    // the _stricmp utility

	int compareStatus = stricmp(mLastName.c_str(), otherPlayer.mLastName.c_str());   // compare last names

	if (compareStatus == 0)  // the last names are the same so do a comparison on the first names to update
		compareStatus = stricmp(mFirstName.c_str(), otherPlayer.mFirstName.c_str()); // so compare the first names

	return compareStatus;

} */

//-----------------------------------------------------------------------------------------------//
// setName
// sets the full name (first and last) for a player object
//-----------------------------------------------------------------------------------------------//
void BaseballPlayer::setName(string firstName, string lastName) {
	mFirstName = firstName;
	mLastName = lastName;
}