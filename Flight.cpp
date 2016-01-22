//
// Created by kadash on 16.01.16.
//

#include "Flight.h"

string Flight::generateName() {

    srand((unsigned int) time(NULL));
    string travelNames[] = {
            "Flight of dream",
            "Flight of Love",
            "Flight of What You want"
    };
    int sizeOfArr = (int) sizeof(travelNames) / sizeof(travelNames[0]);
    int randomNameIndex = (rand() % sizeOfArr);
    return travelNames[randomNameIndex];
}

Flight::Flight(int id)  : Travel(id) {
    setTravelName(generateName());
}

string Flight::toString() {
    return "Type is Flight";
}


Flight::Flight(int id, int numberOfStaff, string travelName, string captainName) : Travel(id, travelName) {
    this->nameOfCaptain = captainName;
    this->numberOfStaff = numberOfStaff;
    this->setTravelName(travelName);
}
