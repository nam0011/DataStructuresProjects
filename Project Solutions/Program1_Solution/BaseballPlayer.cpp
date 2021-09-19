/* File: BaseballPlayer.cpp
   Program 1: Beth Allen
              August 2018
   Implementation of the class BaseballPlayer
   All of the methods are contained in this file.
*/
#include "BaseballPlayer.h"

//-----------------------------------------------------------------------------------------------//
// Default Constructor
// Sets numberic values to zeros, and other values to either empty strings or default values
//-----------------------------------------------------------------------------------------------//
BaseballPlayer::BaseballPlayer() {

	mFirstName = "unknown";
	mLastName = "unknown";
	for (int i = 0; i < STATS_DATA_LENGTH; i++)
		mHitting[i] = 0;
}

//-----------------------------------------------------------------------------------------------//
// read(input)
// This method reads the baseball player's data from a single line on an input stream.
// Some special restrictions - the player's first name and last name can each only consist of
// a single word (no embedded spaces), other wise the input will be read in incorrectly.
// There must also be all the statistics data values on the line.
// The order of input is firstname lastname plateapps atbats singles doubles triples homeruns bbs hbp
//
// NOTE: This assumes the input is on the stream and is valid data.  We can update this with
// more error checking later.
//
// Parameters:
//    input   : a variable representing the input stream to read data from
//-----------------------------------------------------------------------------------------------//
void BaseballPlayer::read(istream &input) {

	input >> mFirstName >> mLastName;
	for (int i = 0; i < STATS_DATA_LENGTH; i++)
		input >> mHitting[i];				// read in each stat from input stream

}


//-----------------------------------------------------------------------------------------------//
// computeStats
// This function currently computes the player's batting average and OBP based on the hitting data.
// Later revisions will compute additional player statistics.
//-----------------------------------------------------------------------------------------------//
void BaseballPlayer::computeStats() {
	double numberOfHits = 0;
	mBattingAverage = 0.0;
	
	for (int i = SINGLES; i <= HRS; i++) {// step through the hitting values and sum them
		numberOfHits = numberOfHits + mHitting[i];
	}
	if (mHitting[ATBATS] > 0) {
		mBattingAverage = numberOfHits / mHitting[ATBATS];
		mOnBasePercentage = (numberOfHits + mHitting[BB] + mHitting[HBP]) / mHitting[PAS];
	}
	else {
		mBattingAverage = 0.0;		// if there was a 0 in the at bats, we can't divide by it
		mOnBasePercentage = 0.0;
	}
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
// getBattingAverage()
// Used to retrieve the batting average for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getBattingAverage() {
	return mBattingAverage;
}

//-----------------------------------------------------------------------------------------------//
// getOBP()
// Used to retrieve the on base percentage for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getOBP() {
	return mOnBasePercentage;
}