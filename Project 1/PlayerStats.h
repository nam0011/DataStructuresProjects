/*  Nathan Moore
 *  8/22/20
 *  CS221-01
 *  Header for main program to access Baseball Player Stat Calculator
 */


#include <iomanip>          //declaring standard namespace and default cpp libaries to be included within header file
#include <iostream>


#define STATS_DATA_LENGTH 8  // how many numeric stats are in the array

using namespace std;


class PlayerStats {
public:    //public functions for main to call to reach private function abilities

    void statsCalc();

private:                    //Private variables  and functions to class Player

    void playerInitialize();
    void getData(int stats[]);
    void OBP();
    void AVG();
    void read(istream &input);
    void printName(string fName, string lName);
    void repeat();
    double ComputeStat();

    double batAverage();
    double oBPerc();

    double printAVG , printOBP;

    string firstName , lastName ;
    double batAVG, oBP;
    int  rawStats[STATS_DATA_LENGTH];
    typedef enum { PAS, ATBATS, SINGLES, DOUBLES, TRIPLES, HRS, BB, HBP} mBattingIndex;
    char answerMain = 'N';
};