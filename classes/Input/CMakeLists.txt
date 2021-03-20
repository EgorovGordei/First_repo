cmake_minimum_required(VERSION 2.7)

message("Creating InputController library")
project("lib_project")

set(SOURCES InputKeyboard.cpp InputKeyboard.h InputController.cpp InputController.h kbhit.cpp kbhit.h InputFactory.cpp InputFactory.h)
add_library(InputController.lib SHARED ${SOURCES})

target_include_directories(InputController.lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("InputController created")

