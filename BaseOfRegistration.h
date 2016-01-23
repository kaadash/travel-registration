//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_BASE_H
#define FLY_REGISTRATION_BASE_H

#include <cstdio>
#include <vector>
#include <iostream>
#include "Flight.h"

using namespace std;
template <typename T> class BaseOfRegistration {
private:
    vector<T*> registrationContainer;

public:
    void operator+=(T *element) {
        registrationContainer.push_back(element);
    }
//
    void operator-=(const int index) {
        int iter = 0;
        int indexToRemove = 0;
        for ( auto &i : registrationContainer) {
            if(i->getId() == index) {
                indexToRemove = iter;
            }
            iter++;
        }
        registrationContainer.erase(registrationContainer.begin() + indexToRemove);
    }

    T* getLastElement() {
       return registrationContainer.back();
    }

    T* getElement (int index) {
        bool indexFound = false;
        int iter = 0;
        int indexToChoose = 0;
        while(!indexFound) {
            for ( auto &i : registrationContainer) {
                if(i->getId() == index) {
                    indexToChoose = iter;
                    indexFound = true;
                }
                iter++;
            }
            if(!indexFound) {
                iter = 0;
                cout << "Please check if this id of travel exists and try again" << endl;
                cin >> index;
            }
        }
        return registrationContainer.at((unsigned long) indexToChoose);
    }

    const vector<T *> &getRegistrationContainer() const {
        return registrationContainer;
    }

    void setRegistrationContainer(const vector<T *> &registrationContainer) {
        BaseOfRegistration::registrationContainer = registrationContainer;
    }
};


#endif //FLY_REGISTRATION_BASE_H
