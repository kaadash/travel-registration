//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_CLIENT_H
#define FLY_REGISTRATION_CLIENT_H


#include <boost/serialization/nvp.hpp>
#include "Travel.h"
#include "BaseOfRegistration.h"

class Client {
private:
    bool isProgramRunning;
    BaseOfRegistration<Travel> allRegistrations;
    BaseOfRegistration<Travel> allAvailableRegistrations;
    BaseOfRegistration<Travel> allUnavailableRegistrations;

public:
    Client();
    void registerTravel();
    void cancelRegistration();
    void displayAllRegistrations();
    void displayAllAvailableRegistrations();
    void displayAllRegisteredTravel();
    void prepareInterface();
    void prepareSampleData();
    void leaveProgram();
    void displayTip();
    void saveToFile(BaseOfRegistration<Travel>, string);
    void loadFromFile(string, BaseOfRegistration<Travel>);
    void saveAll();
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

    const BaseOfRegistration<Travel> &getAllUnavailableRegistrations() const {
        return allUnavailableRegistrations;
    }

    void setAllUnavailableRegistrations(const BaseOfRegistration<Travel> &allUnavailableRegistrations) {
        Client::allUnavailableRegistrations = allUnavailableRegistrations;
    }
};


#endif //FLY_REGISTRATION_CLIENT_H
