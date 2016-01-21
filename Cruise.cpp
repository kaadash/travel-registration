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
    return "Type is Cruise";
}

Cruise::Cruise() {
    setTravelName(generateName());
}
