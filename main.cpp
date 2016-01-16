#include <iostream>
#include <fstream>
#include "Client.h"
#include <ctime>

using namespace std;

int main() {
    srand ((unsigned int) time(NULL));
    Client client;
    client.prepareInterface();
    return 0;
}