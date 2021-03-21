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
include_directories(${CDIR} "${CDIR}/Input/" "${CDIR}/Main/" "${CDIR}/Painter/" "${CDIR}/Additional/" "${CDIR}/BattleField" "${CDIR}/InGameObjects/")
add_executable(main main.cpp Main/Menu.cpp Main/Menu.h Main/Shop.h Main/Shop.cpp Main/Game.h Main/Game.cpp Main/Environment.cpp Main/Environment.h Main/Board.cpp Main/Board.h Painter/PainterMenu.cpp Painter/PainterMenu.h Painter/PainterShop.cpp Painter/PainterGame.cpp Painter/PainterGame.h Painter/Painter.h Painter/PainterFactory.cpp Painter/PainterFactory.h Painter/Painter.h Painter/Painter.cpp Painter/PainterConsole.h Painter/PainterConsole.cpp Additional/Stats.cpp Additional/Stats.h BattleField/Level.cpp BattleField/Level.cpp BattleField/Cell.h BattleField/Cell.cpp InGameObjects/Archer.h InGameObjects/Archer.cpp InGameObjects/Army.h InGameObjects/Army.cpp InGameObjects/Building.h InGameObjects/Building.cpp InGameObjects/BuildingFactory.h InGameObjects/Castle.h InGameObjects/Cavalery.h InGameObjects/Custom_Unit.h InGameObjects/Custom_Unit.cpp InGameObjects/GameObject.h InGameObjects/GameObjectFactory.h InGameObjects/GameObjectFactory.cpp InGameObjects/Player.h InGameObjects/Player.cpp InGameObjects/PlayerBuildings.h InGameObjects/Squad.h InGameObjects/Squad.cpp InGameObjects/Swordsman.h InGameObjects/UserBuildings.h InGameObjects/Warrior.h InGameObjects/Warrior.cpp InGameObjects/WarriorFactory.h InGameObjects/WarriorFactory.cpp)

# step 2
# compile InputController.lib
add_subdirectory(./Input/)
target_link_libraries(main InputController.lib)


