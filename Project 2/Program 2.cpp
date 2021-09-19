/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  Team Statistics Calculator Using Files as input and output
 */


#include "PlayerList.h"  // declaration needed to use PlayerList class
using namespace std;    //using standard namespace unless otherwise specified


int main(void) {    //beginning of main argument

    string in;                  //creation of main function variables
    string out;
    string dates, datesOut;
    double teamBat = 0.0;
    double teamBatAvg = 0.0;

    ifstream inFile;        //creating instream variable
    ofstream outFile;       //creating outstream variable

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


    Player player;           //creating player object
    PlayerList myPlayers;   //creating player list object

    while (!inFile.eof()) {         //while file is open
        player.read(inFile);    //read from the file
        myPlayers.add(player);      //add objects read from file to list
    }


    myPlayers.resetToStart();
    while(myPlayers.hasNext()){
        player = myPlayers.getNext();
        player.computeStat();
        teamBat += player.batAVG;
        teamBatAvg = teamBat/myPlayers.listLength;
    }

    outFile << "BASEBALL TEAM REPORT --- " << myPlayers.getSize() << " PLAYERS FOUND IN FILE" << endl;     //how many players are in my list
    outFile<<left<<setw(22)<<"OVERALL BATTING AVERAGE: " <<setprecision(3)<<teamBatAvg<<endl<<endl;
    outFile<<internal<<setw(15)<<"PLAYER LIST"<<endl;
    outFile <<left<<setw(10)<< "LASTNAME"<<setw(10)<<"FIRSTNAME"<<"|"<<setw(7)<<"AVG"<<setw(7)<<"OPS"<<endl;
    outFile <<"----------------------------------"<<endl;

    myPlayers.resetToStart();
    while(myPlayers.hasNext()){
        player = myPlayers.getNext();
        player.statsCalc(outFile);
    }


    myPlayers.resetToStart();           //resetting list to beginning    *********   this function is solely to clear entire list not player by player
    while (myPlayers.hasNext()) {       //loop for anytime list has a next player
        player = myPlayers.getNext();      // the loop makes the player object equal to the object in the list
        if (!myPlayers.remove(player)) {     //if the player object is not equal to an object in the list it is not removed
            cout << "Unable to remove date\n";      //prompt for failure
       }
    }


    myPlayers.resetToStart();   //resetting to start at
    myPlayers.dump(cout);   //dumping list to cout
    myPlayers.~PlayerList();    //clearing memory used by program

    cout << myPlayers.isEmpty();  //boolean check to return 1 if list is empty

    inFile.close();     //closing files
    outFile.close();

    return 0;
}