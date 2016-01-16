//
// Created by kadash on 16.01.16.
//

#include <iostream>
#include "Client.h"
#include "Flight.h"
#include "Cruise.h"
#include "MixedTravel.h"

using namespace std;
void Client::registerTravel() {
    int choice;
    cout << "Please write id of travel you want to register" << endl;
    cin >> choice;

}

void Client::cancelRegistration() {

}

void Client::displayAllRegistrations() {
    for ( auto &i : allRegistrations.getRegistrationContainer() ) {
        cout << i.getId() << i.getTravelName() << endl;
    }
}

void Client::leaveProgram() {
    isProgramRunning = false;
}

void Client::prepareInterface() {
    prepareSampleData();
    int choice;
    cout << "Choose what do you want: " << endl;
    cout << "Press: " << endl;
    cout << "1: to register travel" << endl;
    cout << "2: to cancel registration" << endl;
    cout << "3: to display all registrations" << endl;
    cout << "0: to exit " << endl;
    while(isProgramRunning) {
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

void Client::displayAllAvailableRegistrations() {
    for ( auto &i : allAvailableRegistrations.getRegistrationContainer() ) {
        cout << i.getId() << i.getTravelName() << endl;
    }
}

void Client::prepareSampleData() {
    //    TODO: remove MOCKUP
    Flight newFlight(1);
    Cruise newCruise(2);
    MixedTravel newMixedTravel(3);
    allRegistrations.addToContainer(newFlight);
    allRegistrations.addToContainer(newCruise);
    allRegistrations.addToContainer(newMixedTravel);
}
