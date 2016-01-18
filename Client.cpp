//
// Created by kadash on 16.01.16.
//

#include <iostream>
#include "Client.h"
#include "Flight.h"
#include "Cruise.h"
#include "MixedTravel.h"
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

using namespace std;
void Client::registerTravel() {
    int choice;
    cout << "Please write id of travel from list, you want to register" << endl;
    cin >> choice;
    cout << allRegistrations.getElement(0)->getId();
    Travel* travelToRegister = allAvailableRegistrations.getElement(choice);
    allUnavailableRegistrations += travelToRegister;
    cout << "Success! You registered " << travelToRegister->getId() << " : " << travelToRegister->generateName();
    allAvailableRegistrations -= choice;
}

void Client::cancelRegistration() {
    int choice;
    cout << "Please write id of travel from list, you want to cancel" << endl;
    cin >> choice;
    Travel* travelToCancelRegister = allUnavailableRegistrations.getElement(choice);
    allAvailableRegistrations += travelToCancelRegister;
    cout << "You cancel registration " << travelToCancelRegister->getId() << " : " << travelToCancelRegister->generateName();
    allUnavailableRegistrations -= choice;
}

void Client::displayAllRegistrations() {
    for ( auto &i : allRegistrations.getRegistrationContainer() ) {
        cout << i->getId() << i->getTravelName() << endl;
    }
}

void Client::displayAllAvailableRegistrations() {
    for ( auto &i : allAvailableRegistrations.getRegistrationContainer() ) {
        cout << i->getId() << i->getTravelName() << endl;
    }
}

void Client::displayAllRegisteredTravel() {
    for ( auto &i : allUnavailableRegistrations.getRegistrationContainer() ) {
        cout << i->getId() << i->getTravelName() << endl;
    }
}

void Client::leaveProgram() {
    isProgramRunning = false;
}

void Client::displayTip() {
    cout << "Choose what do you want: " << endl;
    cout << "Press: " << endl;
    cout << "1: to register travel" << endl;
    cout << "2: to cancel registration" << endl;
    cout << "3: to display all registrations" << endl;
    cout << "0: to exit " << endl;
}

void Client::prepareInterface() {
    prepareSampleData();
    int choice;
    while(isProgramRunning) {
        displayTip();
        cin >> choice;
        switch (choice) {
            case 0:
                leaveProgram();
                break;
            case 1:
                displayAllAvailableRegistrations();
                registerTravel();
                break;
            case 2:
                displayAllRegisteredTravel();
                cancelRegistration();
                break;
            case 3:
                displayAllRegistrations();
                break;
            default:
                cout << "Incorrect choice - try again";
                break;
        }
    }

}

Client::Client() {
    isProgramRunning = true;
}

void Client::prepareSampleData() {
    //    TODO: remove MOCKUP
    for (int i = 0; i < 25; ++i) {
        if(i < 10) {
            Flight *newFlight = new Flight(i);
            allRegistrations += newFlight;
            allAvailableRegistrations += newFlight;
        }
        if(i >=10 && i < 20) {
            Cruise *newCruise = new Cruise(i) ;
            allRegistrations += newCruise;
            allAvailableRegistrations += newCruise;
        }
        if(i >= 20 ) {
            MixedTravel *newMixedTravel = new MixedTravel(i);
            allRegistrations += newMixedTravel;
            allAvailableRegistrations += newMixedTravel;
        }
    }
}
