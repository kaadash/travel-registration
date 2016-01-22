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
    string textToDisplay = "id: " + to_string(this->getId()) + " travel name: "
                           + this->getTravelName() + " number of staf: " + to_string(this->numberOfStaff)
                           + " name of captain: " + this->nameOfCaptain;
    return textToDisplay;
}


Flight::Flight(int id, int numberOfStaff, string travelName, string captainName) : Travel(id, travelName) {
    this->nameOfCaptain = captainName;
    this->numberOfStaff = numberOfStaff;
    this->setTravelName(travelName);
}

string Flight::serializeClass() {
    return ";f;;" + to_string(this->getId()) + ";;" + to_string(this->numberOfStaff) + ";;"
            + this->getTravelName() + ";;" + this->getNameOfCaptain() + ";";

}
