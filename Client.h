//
// Created by kadash on 16.01.16.
//

#ifndef FLY_REGISTRATION_CLIENT_H
#define FLY_REGISTRATION_CLIENT_H


class Client {
private:
    bool isProgramRunning;

public:
    Client();
    void registerTravel();
    void cancelRegistration();
    void displayAllRegistration();
    void prepareInterface();
    void leaveProgram();

    bool isIsProgramRunning() const {
        return isProgramRunning;
    }

    void setIsProgramRunning(bool isProgramRunning) {
        Client::isProgramRunning = isProgramRunning;
    }
};


#endif //FLY_REGISTRATION_CLIENT_H
