#include "Location.h"

//minor assistance from chatgpt on for the location display format
Location::Location(string n, string d){
    locationName = n;
    description = d;
}

void Location::displayLocation(){
    cout << "\n=== " << locationName << " ===\n";
    cout << description << endl;
}
