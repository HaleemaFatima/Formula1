#include <iostream>
#include <ctime>
#include "driver.h"
#include "event.h"
#include "teamstats.h"
#include "race.h"
using namespace std;

int main() {
    srand(time(0)); 

    //35 laps race simulator
    RaceSimulator race(35);

//List of 20 drivers
Driver allDrivers[20] = {
        {"Max Verstappen",  "Red Bull",      1},
        {"Yuki Tsunoda",    "Red Bull",     22},
        {"Charles Leclerc", "Ferrari",      16},
        {"Lewis Hamilton",  "Ferrari",      44},
        {"Lando Norris",    "McLaren",       4},
        {"Oscar Piastri",   "McLaren",      81},
        {"George Russell",  "Mercedes",     63},
        {"Kimi Antonelli",  "Mercedes",     12},
        {"Fernando Alonso", "Aston Martin", 14},
        {"Daniel Riccardo", "Aston Martin", 18},
        {"Liam Lawson",     "RB",           30},
        {"Isack Hadjar",    "RB",            6},
        {"Oliver Bearman",  "Haas",         87},
        {"Esteban Ocon",    "Haas",         31},
        {"Pierre Gasly",    "Alpine",       10},
        {"Jack Doohan",     "Alpine",        7},
        {"Alex Albon",      "Williams",     23},
        {"Carlos Sainz",    "Williams",     55},
        {"Nico Hulkenberg", "Kick Sauber",  27},
        {"Gabriel Bortoleto","Kick Sauber",  5}
    };

     for (int i=0;i<20;i++) {
        allDrivers[i].pitWindowStart = 10;
        allDrivers[i].pitWindowEnd = 20;
        allDrivers[i].pitLap = (rand()%11)+10; //random pit stop between lap 10 to 20

        race.addDriver(allDrivers[i]);
    }
     
    //for ranking teams
    string teamList[10] = 
     {"Red Bull", "Ferrari", "McLaren", "Mercedes", "Aston Martin","RB", "Haas", "Alpine", "Williams", "Kick Sauber"};

    for (int i = 0; i < 10; i++) {
    race.teamStats[teamList[i]] = TeamStats();
}

    race.runQualifying();

    race.runRace();

    return 0;
}
