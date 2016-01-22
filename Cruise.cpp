//
// Created by kadash on 16.01.16.
//

#include "Cruise.h"

string Cruise::generateName() {

    srand ((unsigned int) time(NULL));
    string travelNames [] = {
            "Cruise of dream",
            "Cruise of Love",
            "Cruise of What You want"
    };
    int sizeOfArr = (int)sizeof(travelNames)/sizeof(travelNames[0]);
    int randomNameIndex = (rand() % sizeOfArr);
    return travelNames[randomNameIndex];
}

Cruise::Cruise(int id)  : Travel(id) {
    setTravelName(generateName());
}

string Cruise::toString() {
    string textToDisplay = "id: " + to_string(this->getId()) + " travel name:  "
                           + this->getTravelName() + " length of travel in km " + to_string(this->lengthOfCruise);
    return textToDisplay;
}

Cruise::Cruise(int id, int lengthOfTravel, string travelName) : Travel(id, travelName) {
    this->lengthOfCruise = lengthOfTravel;
}

string Cruise::serializeClass() {
    return "c;" + to_string(this->getId()) + ";;" + to_string(this->lengthOfCruise) + ";;"
           + this->getTravelName() + ";";
}
