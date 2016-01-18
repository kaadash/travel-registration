//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_FLIGHT_H
#define FLY_REGISTRATION_FLIGHT_H


#include "Travel.h"

class Flight: public Travel{

public:
    Flight(int id);
    string generateName();
};


#endif //FLY_REGISTRATION_FLIGHT_H
