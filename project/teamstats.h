#ifndef TEAMSTATS_H
#define TEAMSTATS_H

#include <string>
using namespace std;

class TeamStats {
public:
    int points;
    int podiums;

    TeamStats();
    void addPoints(int p);
    void addPodium();
    void printStats(string teamName);
};

#endif
