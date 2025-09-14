#include <iostream>
#include <algorithm>
#include <queue>
#include "race.h"

using namespace std;

RaceSimulator::RaceSimulator(int laps) {
    totalLaps = laps;
}

void RaceSimulator::addDriver(Driver d) {
    drivers.push_back(d);
}

void RaceSimulator::addEvent(Event e) {
    eventQueue.push(e); //adding events queue
}

void RaceSimulator::runQualifying() {
    cout<<"\n===== QUALIFYING SESSION =====\n";

    for (int i = 0; i < drivers.size(); i++) {
        double randomTime = 85 + (rand() % 300 - 150) / 10.0;
        drivers[i].qualifyingTime = randomTime; //from drivers class, setting quali time to random time
        cout<<drivers[i].name<<" (" <<drivers[i].team << ") - Quali Lap: "<<randomTime<<endl;
    }

    //sorting drivers based on qualifying time
    for (int i = 0; i < drivers.size() - 1; i++) {
        for (int j = i + 1; j < drivers.size(); j++) {
            if (drivers[j].qualifyingTime < drivers[i].qualifyingTime) {
                Driver temp = drivers[i];
                drivers[i] = drivers[j];
                drivers[j] = temp;
            }
        }
    }

    cout << "\n--- STARTING GRID ---\n";
    for (int i = 0; i < drivers.size(); i++) {
        cout<<(i + 1)<<") "<<drivers[i].name<<" ("<<drivers[i].team<<") - "<<drivers[i].qualifyingTime<<endl;
    }

    //getting ready for gp
    for (int i = 0; i < drivers.size(); i++) {
        drivers[i].totalTime = drivers[i].qualifyingTime;
        drivers[i].currentLap = 0;
        drivers[i].points = 0;
    }

    cout<<"\nWE ARE READY FOR THE GP!!"<<endl;
}

void RaceSimulator::runRace() {
    cout << "\n===== STARTING THE GRAND PRIX (" << totalLaps << " LAPS) =====\n";

    for (int lap = 1; lap <= totalLaps; lap++) {
        cout << "\n===== LAP " << lap << " =====\n";

        //pit stop scheduling
        for (int i = 0; i < drivers.size(); i++) {
            if (drivers[i].pitLap==lap) { //matching the random generated lap to the current lap (working in main)
                Event pitStop(lap, &drivers[i], "PIT_STOP"); //making a pit stop event
                addEvent(pitStop); //adding that event in queue of events 
            }
        }

        //whoever gets into the pit first gets out first
        for (int i = 0; i < eventQueue.size(); i++) {
            Event e = eventQueue.front(); //drivers waiting in line, points to the first driver
            eventQueue.pop(); //pop the first one dequeue
            e.handleEvent();
            
        }

        //running the race
        for (int i = 0; i < drivers.size(); i++) {
            drivers[i].simulateLap();
        }

        showTop3();
    }

    assignPoints();
    showFinalResults();
}



void RaceSimulator::showTop3() {
    cout<<"\n--- Drivers on Podium ---\n";

    vector<Driver*> minHeap;

    //Inserting all drivers into the heap
    for (int i=0; i<drivers.size(); i++) {
        minHeap.push_back(&drivers[i]); //pushing into the vectors of min heap
        int index=minHeap.size()-1;

        //up heapifying
        while (index>0) {
            int parent=(index-1)/2;
            if (minHeap[parent]->totalTime <= minHeap[index]->totalTime)
                break;

            Driver* temp=minHeap[parent];
            minHeap[parent]=minHeap[index];
            minHeap[index]=temp;
            index=parent;
        }
    }

    //top 3 podium drivers
    for (int i=0; i<3; i++) {
        Driver* top = minHeap[0];
        cout<<(i + 1)<<") "<<top->name<<" - "<<top->totalTime<<endl;

        //Replace root with last element and remove last as its already on podium
        minHeap[0]=minHeap[minHeap.size()-1];
        minHeap.pop_back();

        //Heapify down to find the next fastest driver
        int index = 0;
        while (true) {
            int left=2*index+1;
            int right=2*index+2;
            int smallest=index;

            if (left<minHeap.size()&&minHeap[left]->totalTime<minHeap[smallest]->totalTime) 
                smallest=left;
            if (right<minHeap.size()&&minHeap[right]->totalTime<minHeap[smallest]->totalTime)
                smallest=right;

            if (smallest==index)
                break;

            Driver*temp=minHeap[index];
            minHeap[index]=minHeap[smallest];
            minHeap[smallest]=temp;
            index=smallest;
        }
    }
}


void RaceSimulator::assignPoints() {
    vector<Driver*> ranking; //new list so original wont be modified
    for (int i=0;i<drivers.size(); i++) {
        ranking.push_back(&drivers[i]);
    }

    for (int i=0;i<ranking.size()-1;i++) {
        for (int j=i+1;j<ranking.size();j++) { //sort with the time
            if (ranking[j]->totalTime<ranking[i]->totalTime) {
                Driver* temp=ranking[i];
                ranking[i]=ranking[j];
                ranking[j]=temp;
            }
        }
    }

    int pointsList[10]={25,18,15,12,10,8,6,4,2,1};
    for (int i=0;i<ranking.size();i++) {
        if (i<10) {
            ranking[i]->points=pointsList[i];
            teamStats[ranking[i]->team].addPoints(pointsList[i]); //maps
            if (i<3) {
                teamStats[ranking[i]->team].addPodium(); //maps for podiums
            }
        }
    }
}

void RaceSimulator::showFinalResults() {
    cout << "\n===== FINAL DRIVER STANDINGS =====\n";

    vector<Driver*> sorted;
    for (int i = 0; i < drivers.size(); i++) {
        sorted.push_back(&drivers[i]);
    }

    for (int i=0;i<sorted.size()-1;i++) {
        for (int j=i+1; j<sorted.size();j++) {
            if (sorted[j]->totalTime<sorted[i]->totalTime){
                Driver*temp=sorted[i];
                sorted[i]=sorted[j];
                sorted[j]=temp;
            }
        }
    }

    for (int i=0; i<sorted.size();i++) {
        cout<<(i + 1)<<") "<<sorted[i]->name<<" ("<<sorted[i]->team <<") - "<<sorted[i]->totalTime<<"s - Points: "<<sorted[i]->points<<endl;
    }

    cout<<"\n===== FINAL TEAM STANDINGS =====\n";
    for (auto it=teamStats.begin();it!=teamStats.end();it++) {
        auto teamData=it->second;       //points or podiums
        string teamName=it->first;       //name of the team    
        teamData.printStats(teamName);      //calling print method from ts class

    }
}
