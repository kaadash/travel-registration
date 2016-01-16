//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_CLIENT_H
#define FLY_REGISTRATION_CLIENT_H


#include "Travel.h"
#include "BaseOfRegistration.h"

class Client {
private:
    bool isProgramRunning;
    BaseOfRegistration<Travel> allRegistrations;
    BaseOfRegistration<Travel> allAvailableRegistrations;

public:
    Client();
    void registerTravel();
    void cancelRegistration();
    void displayAllRegistrations();
    void displayAllAvailableRegistrations();
    void prepareInterface();
    void prepareSampleData();
    void leaveProgram();
    bool isIsProgramRunning() const {
        return isProgramRunning;
    }

    void setIsProgramRunning(bool isProgramRunning) {
        Client::isProgramRunning = isProgramRunning;
    }

    const BaseOfRegistration<Travel> &getAllAvailableRegistrations() const {
        return allAvailableRegistrations;
    }

    void setAllAvailableRegistrations(const BaseOfRegistration<Travel> &allAvailableRegistrations) {
        Client::allAvailableRegistrations = allAvailableRegistrations;
    }
};


#endif //FLY_REGISTRATION_CLIENT_H
