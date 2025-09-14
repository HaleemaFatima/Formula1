#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Driver; // forward‐declaration, we only store a pointer

class Event {
public:
    int lap;          // lap number at which the event triggers
    Driver* driver;   // pointer to the driver involved
    string type;      // "PIT_ENTRY" or "PIT_EXIT"

    Event(int l, Driver* d, string t);
    void handleEvent();
};

#endif
