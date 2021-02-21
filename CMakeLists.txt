project(VideoStoreRefactoring)

cmake_minimum_required(VERSION 2.8.12)

# DOWNLOAD AND INCLUDE GTEST
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)


###




# include_directories(/usr/local/include/ $ENV{GTEST_DIR}/include $ENV{GMOCK_HOME}/googlemock/include)
# link_directories($ENV{GMOCK_HOME}/build/lib $ENV{GMOCK_HOME}/build/lib)


add_definitions(-std=c++17)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -pthread")

set(sources
   main.cpp
   MovieTest.cpp
   RentalTest.cpp
   CustomerTest.cpp
   Movie.cpp
   Rental.cpp
   Customer.cpp
   NewReleasePrice.cpp
   RegularPrice.cpp
   ChildrensPrice.cpp
   Price.cpp)
add_executable(testVideoStoreRefactoring ${sources})
target_link_libraries(testVideoStoreRefactoring pthread)
# target_link_libraries(testVideoStoreRefactoring gmock)
# target_link_libraries(testVideoStoreRefactoring gtest)
target_link_libraries(testVideoStoreRefactoring gtest_main)
target_link_libraries(testVideoStoreRefactoring gmock_main)
# add_test(NAME example_test COMMAND example)
