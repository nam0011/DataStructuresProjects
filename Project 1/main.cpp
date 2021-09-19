/*  Nathan Moore
 *  8/22/20
 *  CS221-01
 *  Player Stat Calculator Using User Input to Gather Variable Values
 */

#include "PlayerStats.h" //including header file to include all class functions as well as default cpp librarys and namespace

int main() {        //begin of main function

    PlayerStats baseballPlayer;     //creating an object called baseballPlayer

    baseballPlayer.statsCalc();     //running public function statsCalc to enter and return player stats

    return 0;       //returning 0 to console if program executed and closed properly
}