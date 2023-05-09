cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_executable(test ./src/test.cc)

target_include_directories(test PRIVATE ./include)

target_link_libraries(test gtest pthread)
