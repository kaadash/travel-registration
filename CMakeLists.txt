cmake_minimum_required(VERSION 3.3)
project(fly_registration)

message(STATUS "start running cmake...")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BaseOfRegistration.cpp BaseOfRegistration.h Cruise.cpp Cruise.h Flight.cpp Flight.h MixedTravel.cpp MixedTravel.h Travel.cpp Travel.h Client.cpp Client.h)
add_executable(fly_registration ${SOURCE_FILES})