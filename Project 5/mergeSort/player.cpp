/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  Player.cpp defines public and private class functions used by end user to calculate and display player attributes
 */


#include "Player.h" //inclusion of header file to access and functions and variables
#include <iomanip>   // needed for output formatters like width and fill
using namespace std;

Player::Player()                    //default constructor
{
    firstName = "unknown";
    lastName = "unknown";
    for (int i = 0; i < STATS_DATA_LENGTH; i++)
        rawStats[i] = 0;
}

void Player::read(istream& inFile) {        //function to read from file and store variables into array

    inFile >> lastName >> firstName ;

    for(int i = 0; i < STATS_DATA_LENGTH; i++){
        inFile >> rawStats[i];
    }
}

void Player::print(ostream &outFile) {      //function to print out to output file for testing

    outFile << firstName << " " << lastName << " ";

    for(int i = 0; i < STATS_DATA_LENGTH; i++){
        outFile << " " << rawStats[i] << " ";
    }
    outFile<<endl;
}

void Player::statsCalc(ostream &outFile){           //statistics calculator that calls on private functions to print pertinent information to file
    printName(lastName, firstName, outFile);
    computeStat();
    AVG(outFile);
    OPS(outFile);
}

void Player::computeStat(){   //setter for oBP and batAVG

    double numberOfHits = 0;
    batAVG = 0.0;
    slug = 0.0;
    oPS = 0.0;

    for (int i = SINGLES; i <= HRS; i++) {// step through the hitting values and sum them
        numberOfHits = numberOfHits + rawStats[i];
    }
    if (rawStats[ATBATS] > 0) {
        batAVG = numberOfHits / rawStats[ATBATS];
        oBP = (numberOfHits + rawStats[BB] + rawStats[HBP]) / rawStats[PAS];
        slug = (rawStats[SINGLES]+(2.0*rawStats[DOUBLES]+(3.0*rawStats[TRIPLES])+(4.0*rawStats[HRS])))/rawStats[ATBATS];
        oPS = oBP + slug;
    }
    else {
        batAVG = 0.0;		// if there was a 0 in the at bats, we can't divide by it
        oBP = 0.0;
        slug = 0.0;
        oPS = 0.0;
    }
}

void Player::AVG(ostream &output){            //function to print batting average
    output <<setw(7)<< setprecision(3) << batAVG;
}

void Player::OPS(ostream &output){             //function to print on base plus slugging percentage
    output <<setw(7)<< setprecision(3) << oPS <<endl;
}

void Player::printName(string fName, string lName, ostream &output){  //prints players name
    output << setw(10)<< lName <<setw(10)<< fName << "|";
}

bool Player::equals(const Player &player) const     //compares player object to objects stored in list
{
    return lastName.compare(player.lastName) == 0 && firstName.compare(player.firstName) == 0;  // if last name and first name match returns true
}
