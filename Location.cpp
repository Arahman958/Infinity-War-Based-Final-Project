#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>

using namespace std;

class Location{
private:
    string locationName;
    string description;

public:
    Location(string n, string d);
    void displayLocation();
};

#endif
