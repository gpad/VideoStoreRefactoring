project(VideoStoreRefactoring)

cmake_minimum_required(VERSION 2.6)

include_directories(/usr/local/include/ $ENV{GTEST_DIR}/include $ENV{GMOCK_HOME}/googlemock/include)
link_directories($ENV{GMOCK_HOME}/build/lib $ENV{GMOCK_HOME}/build/lib)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -pthread")

set(sources
   main.cpp
   MovieTest.cpp
   RentalTest.cpp
   Movie.cpp
   Rental.cpp)
add_executable(testVideoStoreRefactoring ${sources})
target_link_libraries(testVideoStoreRefactoring pthread)
target_link_libraries(testVideoStoreRefactoring gmock)
target_link_libraries(testVideoStoreRefactoring gtest)
