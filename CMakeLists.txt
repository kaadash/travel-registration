cmake_minimum_required(VERSION 3.3)
project(fly_registration)

message(STATUS "start running cmake...")

find_package(Boost 1.54.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

add_executable(BoostTest main.cpp BaseOfRegistration.cpp BaseOfRegistration.h Cruise.cpp Cruise.h Flight.cpp Flight.h MixedTravel.cpp MixedTravel.h Travel.cpp Travel.h Client.cpp Client.h)

if(Boost_FOUND)

    target_link_libraries(BoostTest ${Boost_LIBRARIES})

endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BaseOfRegistration.cpp BaseOfRegistration.h Cruise.cpp Cruise.h Flight.cpp Flight.h MixedTravel.cpp MixedTravel.h Travel.cpp Travel.h Client.cpp Client.h)
add_executable(fly_registration ${SOURCE_FILES})