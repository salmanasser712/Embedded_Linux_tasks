cmake_minimum_required(VERSION 3.28.3)
project(cmake_testapp)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable Clang-Tidy with MISRA checks
set(CLANG_TIDY_CHECKS
    "-*,clang-analyzer-*,clang-diagnostic-*,clang-misra-*"
)

# Enable Clang-Tidy and specify the checks
set(CMAKE_CXX_CLANG_TIDY
    "clang-tidy;-checks=${CLANG_TIDY_CHECKS}"
)
add_executable(cmake_testapp app.cpp)
