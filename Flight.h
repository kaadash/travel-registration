//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_FLIGHT_H
#define FLY_REGISTRATION_FLIGHT_H


#include "Travel.h"

class Flight: public Travel {
private:
    string nameOfCaptain;
    int numberOfStaff;

public:
    Flight(int id);
    Flight(int, int, string, string);
    string toString();
    string serializeClass();
    string generateName();
    int getNumberOfStaff() const {
        return numberOfStaff;
    }

    void setNumberOfStaff(int numberOfStaff) {
        Flight::numberOfStaff = numberOfStaff;
    }

    const string &getNameOfCaptain() const {
        return nameOfCaptain;
    }

    void setNameOfCaptain(const string &nameOfCaptain) {
        Flight::nameOfCaptain = nameOfCaptain;
    }
};


#endif //FLY_REGISTRATION_FLIGHT_H
