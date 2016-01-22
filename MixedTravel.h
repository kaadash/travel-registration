//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_MIXEDTRAVEL_H
#define FLY_REGISTRATION_MIXEDTRAVEL_H


#include "Travel.h"

class MixedTravel: public Travel {

private:
    int timeToComeBack;
    string destinationNames;

public:
    MixedTravel(int id);

    string generateName();

    MixedTravel(int, int, string, string);
    int getTimeToComeBack() const {
        return timeToComeBack;
    }

    void setTimeToComeBack(int timeToComeBack) {
        MixedTravel::timeToComeBack = timeToComeBack;
    }
    string toString();

    const string &getDestinationNames() const {
        return destinationNames;
    }

    void setDestinationNames(const string &destinationNames) {
        MixedTravel::destinationNames = destinationNames;
    }
};


#endif //FLY_REGISTRATION_MIXEDTRAVEL_H
