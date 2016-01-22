//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_BASE_H
#define FLY_REGISTRATION_BASE_H

#include <cstdio>
#include <vector>
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
        int iter = 0;
        int indexToRemove = 0;
        for ( auto &i : registrationContainer) {
            if(i->getId() == index) {
                indexToRemove = iter;
            }
            iter++;
        }
        return registrationContainer.at((unsigned long) indexToRemove);
    }

    const vector<T *> &getRegistrationContainer() const {
        return registrationContainer;
    }

    void setRegistrationContainer(const vector<T *> &registrationContainer) {
        BaseOfRegistration::registrationContainer = registrationContainer;
    }
};


#endif //FLY_REGISTRATION_BASE_H
