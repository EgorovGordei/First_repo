cmake_minimum_required(VERSION 2.7)

message("Creating InputController library")
project("lib_project")

set(SOURCES kbhit.cpp)
add_executable(InputController.lib ${SOURCES})

target_include_directories(InputController.lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("InputController created")

