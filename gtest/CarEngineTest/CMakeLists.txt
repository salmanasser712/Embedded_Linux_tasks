cmake_minimum_required(VERSION 3.28.3)
project(CarEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

set(GMOCK_INCLUDE_DIRS "/gmock")
set(GMOCK_LIBRARIES "libgmock.a" "libgmock_main.a")

# Add the path to the gtest source code directory
#add_subdirectory(gtest)

include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

message(STATUS "GTest include dirs: ${GTEST_INCLUDE_DIRS}")
message(STATUS "GTest libraries: ${GTEST_LIBRARIES}")
message(STATUS "GMock include dirs: ${GMOCK_INCLUDE_DIRS}")
message(STATUS "GMock libraries: ${GMOCK_LIBRARIES}")

# Add your own source files
add_executable(Test main.cpp car_test.cpp car.cpp)

# Link against gtest library
#target_link_libraries(Test PRIVATE gmock_main)
target_link_libraries(Test ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
