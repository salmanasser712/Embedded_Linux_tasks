cmake_minimum_required(VERSION 3.28.3)
project(cmake_testapp)
set(CMAKE_CXX_STANDARD 17)
add_executable(cmake_testapp Date.cpp testDate.cpp)