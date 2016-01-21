//
// Created by kadash on 16.01.16.
//

#include <iostream>
#include "Travel.h"

string Travel::generateName() {

  string travelNames [] = {
          "Travel of dream",
          "Travel of Love",
          "Travel of What You want"
  };
  int sizeOfArr = (int)sizeof(travelNames)/sizeof(travelNames[0]);
  int randomNameIndex = (rand() % sizeOfArr);
  return travelNames[randomNameIndex];
}

string Travel::toString() {
  return "type is travel";
}
