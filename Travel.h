//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_TRAVEL_H
#define FLY_REGISTRATION_TRAVEL_H


#include <string>

using namespace std;
class Travel {
private:
    enum travelType {FLIGHT, CRUISE, MIXED_TRAVEL};
    int id;
    string travelName;

public:
    Travel(int id) : id(id) {
        this->id = id;
    }

    virtual string generateName() = 0;

    int getId() const {
        return id;
    }

    void setId(int id) {
        Travel::id = id;
    }

    const string &getTravelName() const {
        return travelName;
    }

    void setTravelName(const string &travelName) {
        Travel::travelName = travelName;
    }
};


#endif //FLY_REGISTRATION_TRAVEL_H
