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
#include <fstream>

using namespace std;
void Client::registerTravel() {
    int choice;
    cout << "Please write id of travel from list, you want to register" << endl;
    cin >> choice;
    Travel* travelToRegister = allAvailableRegistrations.getElement(choice);
    allUnavailableRegistrations += travelToRegister;
    cout << "Success! You registered " << travelToRegister->getId() << " : " << travelToRegister->getTravelName();
    allAvailableRegistrations -= choice;
    saveAll();
}

void Client::cancelRegistration() {
    int choice;
    cout << "Please write id of travel from list, you want to cancel" << endl;
    cin >> choice;
    Travel* travelToCancelRegister = allUnavailableRegistrations.getElement(choice);
    allAvailableRegistrations += travelToCancelRegister;
    cout << "You cancel registration " << travelToCancelRegister->getId() << " : " << travelToCancelRegister->getTravelName();
    allUnavailableRegistrations -= choice;
    saveAll();
}

void Client::displayAllRegistrations() {
    for ( auto &i : allRegistrations.getRegistrationContainer() ) {
        cout << i->toString() << endl;
    }
}

void Client::displayAllAvailableRegistrations() {
    for ( auto &i : allAvailableRegistrations.getRegistrationContainer() ) {
        cout << i->toString() << endl;
    }
}

void Client::displayAllRegisteredTravel() {
    for ( auto &i : allUnavailableRegistrations.getRegistrationContainer() ) {
        cout << i->toString() << endl;
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
    loadFromFile("serializedAllRegistrations", &allRegistrations);
    loadFromFile("serializedAvailableRegistrations", &allAvailableRegistrations);
    loadFromFile("serializedUnavailableRegistrations", &allUnavailableRegistrations);
}

void Client::saveToFile(BaseOfRegistration<Travel> baseContainer, string fileName) {
    ofstream myfile;
    string textToSave;
    for ( auto &i : baseContainer.getRegistrationContainer() ) {
        textToSave += i->serializeClass() + "\n";
    }
    textToSave += '~';
//    Proszę zmienić na ścieżkę relatywną lub lokalną do projektu
    myfile.open ("/home/kadash/Prace/fly-registration/" + fileName + ".txt");
    myfile << textToSave;
    myfile.close();

}
// This method is ugly because it isn't universal/reusable and so on - hardcode, hardcode everywhere
void Client::loadFromFile(string fileName, BaseOfRegistration<Travel> *baseOfRegistration) {
    char eachCharacter;
    char typeOfRegistration;
    char endOfFileSign = '~';
    bool wasNewLine = true;
    bool readingProperty = false;
    string propertyText;
    int counterOfObjects = 0;
    int propertyPointer = 0;

    int id = 0;
    int secondPropertyValue;
    string thirdPropertyName;
    string forthPropertyName;
    bool isEndOfFileSign = false;
//    Proszę zmienić na ścieżkę relatywną lub lokalną do projektu
    ifstream myfile ("/home/kadash/Prace/fly-registration/" + fileName + ".txt");
    if (myfile.is_open())
    {
        while (!myfile.eof()) {
            if(wasNewLine) {
                myfile.get(typeOfRegistration);
                wasNewLine = false;
            }

            myfile.get(eachCharacter);

            if (eachCharacter == endOfFileSign) {
                isEndOfFileSign = true;
            }

            if(readingProperty && eachCharacter != ';') {
                propertyText += eachCharacter;
            }

            if (eachCharacter == ';')  {
                if(readingProperty) {
                    if(propertyPointer == 0) {
                        id = stoi(propertyText);
                    }
                    else {
                        switch(propertyPointer) {
                            case 1 :
                                secondPropertyValue = stoi(propertyText);
                                break;
                            case 2 :
                                thirdPropertyName = propertyText;
                                break;
                            case 3 :
                                forthPropertyName = propertyText;
                                break;
                            default:
                                cout << "error with property pointer";
                                break;
                        }
                    }
                    propertyText = "";
                    propertyPointer++;
                }
                readingProperty = !readingProperty;
            }

            if (eachCharacter == '\n' && !isEndOfFileSign){
                switch (typeOfRegistration) {
                    case 'f':
                        *baseOfRegistration += new Flight(id, secondPropertyValue, thirdPropertyName, forthPropertyName);
                        break;
                    case 'm':
                        *baseOfRegistration += new MixedTravel(id, secondPropertyValue, thirdPropertyName, forthPropertyName);
                        break;
                    case 'c':
                        *baseOfRegistration += new Cruise(id, secondPropertyValue, thirdPropertyName);
                        break;
                    default:
                        cout << "Bad type of registration";
                        break;
                }
                counterOfObjects++;
                wasNewLine = true;
                propertyPointer = 0;
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Client::saveAll() {
    saveToFile(allRegistrations, "serializedAllRegistrations");
    saveToFile(allAvailableRegistrations, "serializedAvailableRegistrations");
    saveToFile(allUnavailableRegistrations, "serializedUnavailableRegistrations");
}