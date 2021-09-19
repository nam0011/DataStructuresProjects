#include "PlayerList.h"

using namespace std;    //using standard namespace unless otherwise specified


int main() {    //beginning of main argument


/*
* VARIABLE DECLARATIONS
*/

    string in;                  //creation of main function variables
    string out;
    double teamBat = 0.0;
    double teamBatAvg = 0.0;

    ifstream inFile;        //creating instream variable
    ofstream outFile;       //creating outstream variable



/*
* INPUT AND OUTPUT FILE GET PROMPTS
*/

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



 /*
* BEGINNING OF ARGUMENTS UTILIZING DATA FROM FILES
*/


    Player player;           //creating player object
    PlayerList playerList;  //creating list

    while (!inFile.eof()) {         //while file is open
        player.read(inFile);    //read from the file
        playerList.add(player);
    }
    inFile.close();     //close input file since all data needed is loaded into memory

/**************************************
* REMEMBER TO DELETE LATER
* **************************************
*/
    cout << playerList.listLength << endl;


/*
* COMPUTING EACH PLAYERS BATTING AVERAGE
*/
    playerList.resetToStart();
    while (playerList.hasNext()) {
        player = playerList.getNext();
        player.computeStat();
    }


/*****************************
*  INITIAL PRINT TO OUTFILE
* ****************************
*/
    outFile << "BASEBALL TEAM REPORT --- " << playerList.getSize() << " PLAYERS FOUND IN FILE" << endl;     //how many players are in my list
    outFile << internal << setw(15) << "PLAYER LIST" << endl;
    outFile << left << setw(10) << "LASTNAME" << setw(10) << "FIRSTNAME" << "|" << setw(7) << "AVG" << setw(7) << "OPS" << endl;
    outFile << "----------------------------------" << endl;



/*****************************************
* ****************************************
* * REMEMBER TO DELETE 
* * THIS BLOCK LATER
* ****************************************
* ****************************************
*/


 //   playerList.resetToStart();
    //while (playerList.hasNext()) {
       // player = playerList.getNext();
        //player.statsCalc(outFile);
    //}
    


/***************************************
* MERGE SORT AND PRINT TO FILE 
* **************************************
*/

    playerList.sortBatAVG();

    while (playerList.hasNext()) {
        player = playerList.getNext();
        player.statsCalc(outFile);
    }



//END OF MAIN ARGUMENT
    return 0;
}