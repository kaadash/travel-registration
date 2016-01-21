//
// Created by kadash on 16.01.16.
//

#include "MixedTravel.h"

string MixedTravel::generateName() {

  srand ((unsigned int) time(NULL));
  string travelNames [] = {
          "Travel of dream",
          "Travel of Love",
          "Travel of What You want"
  };
  int sizeOfArr = (int)sizeof(travelNames)/sizeof(travelNames[0]);
  int randomNameIndex = (rand() % sizeOfArr);
  return travelNames[randomNameIndex];
}

MixedTravel::MixedTravel(int id)  : Travel(id) {
  setTravelName(generateName());
}

string MixedTravel::toString() {
  return "Type is Mixed";
}
