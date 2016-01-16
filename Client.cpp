//
// Created by kadash on 16.01.16.
//

#include <iostream>
#include "Client.h"
using namespace std;
void Client::registerTravel() {

}

void Client::cancelRegistration() {

}

void Client::displayAllRegistration() {

}

void Client::leaveProgram() {
    isProgramRunning = false;
}

void Client::prepareInterface() {
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
                registerTravel();
                break;
            case 2:
                cancelRegistration();
                break;
            case 3:
                displayAllRegistration();
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
