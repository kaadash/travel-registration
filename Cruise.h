//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_CRUISE_H
#define FLY_REGISTRATION_CRUISE_H


#include "Travel.h"

class Cruise: public Travel {

public:
    Cruise(int id);
    string generateName();
};


#endif //FLY_REGISTRATION_CRUISE_H
