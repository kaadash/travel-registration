//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_MIXEDTRAVEL_H
#define FLY_REGISTRATION_MIXEDTRAVEL_H


#include "Travel.h"

class MixedTravel: public Travel {

private:
    int timeToComeBack;

public:
    MixedTravel(int id);
    string generateName();
    int getTimeToComeBack() const {
        return timeToComeBack;
    }

    void setTimeToComeBack(int timeToComeBack) {
        MixedTravel::timeToComeBack = timeToComeBack;
    }
    string toString();
};


#endif //FLY_REGISTRATION_MIXEDTRAVEL_H
