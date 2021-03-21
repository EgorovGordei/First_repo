#pragma once
#include <memory>
#include "Squad.h"
#include "BuildingFactory.h"

class GameObjectFactory {
public:
	static std::shared_ptr<Squad> CreateSquad(int x, int y, int id);
	static std::shared_ptr<Building> CreateBuilding(int id, int health, int x, int y);
};
