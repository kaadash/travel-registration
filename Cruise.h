//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_CRUISE_H
#define FLY_REGISTRATION_CRUISE_H


#include "Travel.h"

class Cruise: public Travel {
private:
    int lengthOfCruise;

public:
    Cruise(int id);
    string generateName();
    int getLengthOfCruise() const {
        return lengthOfCruise;
    }

    void setLengthOfCruise(int lengthOfCruise) {
        Cruise::lengthOfCruise = lengthOfCruise;
    }
    string toString();

    Cruise();
};


#endif //FLY_REGISTRATION_CRUISE_H
