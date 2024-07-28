cmake_minimum_required(VERSION 3.28.3)
project(gtest_cmake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCE_FILE
    src/Vector.h
    src/Vector.tpp
)
 
# Add test files
set(TEST_FILES
    tests/main.cpp
    tests/VectorDoubleTest.cpp
    tests/VectorIntTest.cpp
    tests/VectorStringTest.cpp
)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add a custom target to run the tests and generate the report
add_custom_target(generate_report
    COMMAND ${CMAKE_COMMAND} -E env GTEST_OUTPUT=json:report/test_report.json ./runTests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests and generating report"
)