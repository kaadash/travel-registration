//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_TRAVEL_H
#define FLY_REGISTRATION_TRAVEL_H


class Travel {
private:
    enum travelType {FLIGHT, CRUISE, MIXED_TRAVEL};
    int id;

public:

    int getId() const {
        return id;
    }

    void setId(int id) {
        Travel::id = id;
    }
};


#endif //FLY_REGISTRATION_TRAVEL_H
