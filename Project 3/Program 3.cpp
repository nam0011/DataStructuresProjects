/*  Nathan Moore
 *  9/23/20
 *  CS221-01
 *  Team Statistics Calculator Using Files as input and output
 */


#include "PlayerList.h"  // declaration needed to use PlayerList class
using namespace std;    //using standard namespace unless otherwise specified


int main() {    //beginning of main argument

    string in;                  //creation of main function variables
    string out;
    string dates, datesOut;
    string first, last, key;
    double teamBat = 0.0;
    double teamBatAvg = 0.0;
    char answer = ' ';


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

    }


    myPlayers.resetToStart();   //reset the list
    while(myPlayers.hasNext()){ //while the list is not at the end
        player = myPlayers.getNext();   //get the next player
        player.computeStat();   //compute the players stats
        teamBat += player.batAVG;   //adder to assist in computing the teams batting average
        teamBatAvg = teamBat/myPlayers.listLength;  //computation of teams total batting average
    }

    outFile << "BASEBALL TEAM REPORT --- " << myPlayers.getSize() << " PLAYERS FOUND IN FILE" << endl;     //how many players are in my list
    outFile<<left<<setw(22)<<"OVERALL BATTING AVERAGE: " <<setprecision(3)<<teamBatAvg<<endl<<endl;     //heading stings for top of file creating sections in file
    outFile<<internal<<setw(15)<<"PLAYER LIST"<<endl;
    outFile <<left<<setw(10)<< "LASTNAME"<<setw(10)<<"FIRSTNAME"<<"|"<<setw(7)<<"AVG"<<setw(7)<<"OPS"<<endl;
    outFile <<"----------------------------------"<<endl;

    myPlayers.resetToStart();       //reset list to beginning for initial outFile creation
    while(myPlayers.hasNext()){     //iterate through list
        player = myPlayers.getNext();   //get the next in the list
        player.statsCalc(outFile);  //calculate stats print to outFile
    }


    do {
        cout << "Would you like to delete a player from this list Y/N: "; //ask if we want to delete
        cin >> answer;    //enter answer

        if (answer == 'Y' || answer == 'y') {   //if yes proceed to delete player
            cout << "Please enter the players name: ";    //ask for name of player to remove
            cin >> first >> last;   //enter name
            key = last + first;   //create key to pass to function to search for node
            myPlayers.removePlayer(key);    //search and delete node

            myPlayers.resetToStart();       //reset list to beginning
            outFile << endl << endl;
            outFile << "Appended List" << endl;
            outFile << "-------------------------------" << endl;
            while (myPlayers.hasNext()) {     //iterate through list
                player = myPlayers.getNext();   //load players
                player.statsCalc(outFile);  //calculate stats and reprint new altered list to outFile
            }
        } else if (answer == 'N' || answer == 'n') {    //if answer is no show goodbye message and kick from loop
            cout << "No more players are to be removed goodbye" << endl;
            break;
        } else {   //if not a valid answer kick from loop
            cout << "invalid input try again" << endl;
            break;
        }
    }while(answer == 'Y' || answer == 'y');

    outFile<<endl<<endl;
    outFile<<"Player List printed backwards"<<endl;
    outFile << "-------------------------------" << endl;



    inFile.close(); //reopen infile for new iteration
    inFile.open(in);

    while (!inFile.eof()) {         //while file is open
        player.read(inFile);    //read from the file
        myPlayers.add(player.lastFirst, player);      //add objects read from file to list
    }

    while(myPlayers.hasPrev()){ //while moving backwards
        player = myPlayers.getPrev();   //get previous
        player.computeStat();   //compute the players stats
        teamBat += player.batAVG;   //adder to assist in computing the teams batting average
        teamBatAvg = teamBat/myPlayers.listLength;  //computation of teams total batting average
    }
    myPlayers.resetToEnd();   //resetting to end of list
    while(myPlayers.hasPrev()){ //while moving backwards through list
        myPlayers.getPrev();    //get previous value
        player.statsCalc(outFile);  //calculate stats print to outFile
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


    cout<<myPlayers.isEmpty();  //boolean check to return 1 if list is empty

    inFile.close();     //closing files
    outFile.close();

    return 0;
}