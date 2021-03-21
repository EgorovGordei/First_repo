cmake_minimum_required(VERSION 2.8)

project(C)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


include_directories(InGameObjects)

add_executable(CTest "${CMAKE_SOURCE_DIR}/main_test.cpp")


enable_testing() 
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(CTest GTest::GTest GTest::Main)
add_test(Tests CTest)

