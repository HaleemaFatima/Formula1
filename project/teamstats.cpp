#include "teamstats.h"
#include <iostream>
using namespace std;

TeamStats::TeamStats() {
    points = 0;
    podiums = 0;
}

void TeamStats::addPoints(int p) {
    points += p;
}

void TeamStats::addPodium() {
    podiums++;
}

void TeamStats::printStats(string teamName) {
    cout<<teamName<<" - "<<points<<" pts | Podiums: "<<podiums<<endl;
}
