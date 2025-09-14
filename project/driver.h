#ifndef DRIVER_H
#define DRIVER_H

#include <string>
using namespace std;

class Driver {
public:
    string name;
    string team;
    int number;

    double totalTime;   
    int currentLap;     
    int points;         

    int pitWindowStart; //10
    int pitWindowEnd;   //20
    int pitLap;         //randomly chosen between start and end
    double qualifyingTime;

    Driver(string n, string t, int num);

    void simulateLap();

};


#endif 
