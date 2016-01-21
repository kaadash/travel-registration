//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_TRAVEL_H
#define FLY_REGISTRATION_TRAVEL_H


#include <string>

using namespace std;
class Travel {
private:
    int id;
    string travelName;

public:
    Travel(int id) : id(id) {
        this->id = id;
    }
    Travel();

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
//    it can be overload operator <<
    virtual string toString();
};


#endif //FLY_REGISTRATION_TRAVEL_H
