//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_FLIGHT_H
#define FLY_REGISTRATION_FLIGHT_H


#include "Travel.h"

class Flight: public Travel {
private:
    int numberOfStaff;

public:
    Flight(int id);
    string generateName();
    int getNumberOfStaff() const {
        return numberOfStaff;
    }

    void setNumberOfStaff(int numberOfStaff) {
        Flight::numberOfStaff = numberOfStaff;
    }
    string toString();
};


#endif //FLY_REGISTRATION_FLIGHT_H
