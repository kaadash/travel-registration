//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_BASE_H
#define FLY_REGISTRATION_BASE_H

#include <cstdio>
#include <vector>
template <typename T> class BaseOfRegistration {
private:
    std::vector<T> registrationContainer;
public:
    void operator+=(const T &element) {
        registrationContainer.push_back(element);
    }

    void operator-=(const int &index) {
        registrationContainer.erase(registrationContainer.begin() + index);
    }

    T getElement (int index) {
        return registrationContainer.at((unsigned long) index);
    }
    const std::vector<T> &getRegistrationContainer() const {
        return registrationContainer;
    }

    void setRegistrationContainer(const std::vector<T> &registrationContainer) {
        BaseOfRegistration::registrationContainer = registrationContainer;
    }
};


#endif //FLY_REGISTRATION_BASE_H
