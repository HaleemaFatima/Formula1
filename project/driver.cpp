#include "driver.h"
#include <iostream>
#include <cstdlib>   
using namespace std;

Driver::Driver(string n, string t, int num) {
    name          = n; //name of the driver
    team          = t; //what team
    number        = num; //their specified number
    totalTime     = 0; //the lap time
    currentLap    = 0;//what lap they are currently on
    //hasPitted     = false;//have they already taken a pit (if yes then we wont send them again unlike max today having 4 pits and ending up 10 LMAOO)
    points        = 0; //what point they earned after winning

    //pit stop system
    pitWindowStart = 0;
    pitWindowEnd   = 0;
    pitLap         = 0;
    qualifyingTime=0.0;
}

void Driver::simulateLap() {
    double lapTime = 85+(rand()%300-150)/10.0;//randomly generate lap time within the range of 85+-15 
    totalTime += lapTime; 
    currentLap++; //moving to the next lap
}


