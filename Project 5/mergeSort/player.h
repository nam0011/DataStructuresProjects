/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  Player.h defines public and private class functions used by Player.cpp and any other further inherited files
 */



//all include values are here because they are inherited by all other files
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;    //using standard namespace unless otherwise defined

#define STATS_DATA_LENGTH 8  // static definition of how many numeric stats are in the array

class Player {  //creation of a class Player
public: //public member functions

    Player();
    void read(istream& in);
    void print(ostream &output);
    void statsCalc(ostream &output);
    bool equals(const Player &player) const;

    //public variables
    void computeStat();
    double batAVG;

private:
    //private member functions
    void AVG(ostream &output);
    void OPS(ostream &output);
    void printName(string fName, string lName, ostream &output);

    //private member variables
    string firstName , lastName ;
    double oBP, slug, oPS;
    int  rawStats[STATS_DATA_LENGTH];
    typedef enum { PAS, ATBATS, SINGLES, DOUBLES, TRIPLES, HRS, BB, HBP} mBattingIndex;
    char answerMain = 'N';

};

