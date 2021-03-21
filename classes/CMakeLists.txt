# step 0
cmake_minimum_required(VERSION 2.7)

# output
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib/)

# project's name
project(main)

# step 1
# create executable
set(CDIR ${CMAKE_SOURCE_DIR})
include_directories(${CDIR} "${CDIR}/Input/" "${CDIR}/Main/" "${CDIR}/Painter/" "${CDIR}/Additional/")
add_executable(main main.cpp Main/Menu.cpp Main/Menu.h Main/Shop.h Main/Shop.cpp Painter/PainterMenu.cpp Painter/PainterMenu.h Painter/PainterShop.cpp Painter/Painter.h Painter/PainterFactory.cpp Painter/PainterFactory.h Painter/Painter.h Painter/Painter.cpp Painter/PainterConsole.h Painter/PainterConsole.cpp Additional/Stats.cpp Additional/Stats.h)

# step 2
# compile InputController.lib
add_subdirectory(./Input/)
target_link_libraries(main InputController.lib)


