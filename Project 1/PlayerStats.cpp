/*  Nathan Moore
 *  8/22/20
 *  CS221-01
 *  PlayerStats.cpp made to define public and private class functions used by end user to calculate and display player attributes
 */


#include "PlayerStats.h"

    void PlayerStats::playerInitialize(){       //Player Constructor initialization
        firstName = "unknown";
        lastName = "unknown";
        for (int i = 0; i < STATS_DATA_LENGTH; i++)
            rawStats[i] = 0;
    }

    void PlayerStats::statsCalc(){
        do {
            playerInitialize();
            read(cin);
            printName(firstName, lastName);
            ComputeStat();
            AVG();
            OBP();
            repeat();
        }while(answerMain == 'Y' || answerMain == 'y');
        if(answerMain == 'N' || answerMain == 'n'){
            cout << "Program One Testing Complete"<<endl;
        }
    }

    void PlayerStats::read(istream &input) {
    cout << "Enter Player Data: ";
    input >> firstName >> lastName;
        for (int i = 0; i < STATS_DATA_LENGTH; i++) {
            input >> rawStats[i];
        }
    }

    double PlayerStats::ComputeStat(){   //setter for oBP and batAVG

    double numberOfHits = 0;
    batAVG = 0.0;

    for (int i = SINGLES; i <= HRS; i++) {// step through the hitting values and sum them
        numberOfHits = numberOfHits + rawStats[i];
    }
    if (rawStats[ATBATS] > 0) {
        batAVG = numberOfHits / rawStats[ATBATS];
        oBP = (numberOfHits + rawStats[BB] + rawStats[HBP]) / rawStats[PAS];
    }
    else {
        batAVG = 0.0;		// if there was a 0 in the at bats, we can't divide by it
        oBP = 0.0;
    }

}

    void PlayerStats::repeat(){     //function to repeat program
        char answer;

        cout<<endl;
        cout<<"Do you wish to enter another players information?: ";
        cin>>answer;
        cout<<endl;
        answerMain = answer;
    }

    double PlayerStats::batAverage() {       //getter for batting average
        return batAVG;
    }

    double PlayerStats::oBPerc() {       //getter for on base percentage
            return oBP;
    }

void PlayerStats::OBP(){             //function to print on base percentage
    cout << "OBP = " << setprecision(3) << oBP << " " <<endl;
}

void PlayerStats::AVG(){            //function to print batting average
    cout << "Batting Average = " << setprecision(3) << batAVG << " ";
}

void PlayerStats::printName(string fName, string lName){    //function to check if players last name ends in an "s" to display correct possessive proper noun
    if(lName.back() == 's'){
        cout <<"     " << fName << " "<< lName<<"' ";
    }else {
        cout <<"     " << fName << " " << lName << "'s ";
    }
}


