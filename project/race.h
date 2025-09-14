#ifndef RACE_H
#define RACE_H

#include <vector>
#include <queue>
#include <unordered_map>
#include "driver.h"
#include "event.h"
#include "teamstats.h"

class RaceSimulator {
public:
    int totalLaps;
    vector<Driver> drivers;                   //all drivers in the field
    queue<Event> eventQueue;                  
    unordered_map<string, TeamStats> teamStats;  //team → TeamStats

    RaceSimulator(int laps);

    void addDriver(Driver d);
    void addEvent(Event e);

    //Qualifying session before the race itself
    void runQualifying();

    //Actual race with “auto‐pit at pitLap” logic
    void runRace();

    //Show the top 3 drivers so far (called every lap)
    void showTop3();

    //After race: assign points (top 10) and update teamStats
    void assignPoints();

    //Print the final 20 drivers (in finishing order) + team standings
    void showFinalResults();
};

#endif // RACE_H
