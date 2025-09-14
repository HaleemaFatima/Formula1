// event.cpp
#include "event.h"
#include "driver.h"
#include <iostream>
using namespace std;

Event::Event(int l, Driver* d, string t) {
    lap=l;
    driver=d;
    type=t;
}

void Event::handleEvent() {
    if (type == "PIT_STOP") {
        cout<<driver->name<<" is entering the pit lane."<<endl;
        driver->totalTime+=20; 
        cout<< driver->name<<" exits the pit lane (+20s)."<<endl;
    }
}

