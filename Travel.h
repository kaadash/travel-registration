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
    Travel();

    Travel(int id) : id(id) {
        this->id = id;
    }

    Travel(int id, string travelName) {
        this->id = id;
        this->travelName = travelName;
    }

//    it can be overload operator <<
    virtual string toString();
    virtual string serializeClass();
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
