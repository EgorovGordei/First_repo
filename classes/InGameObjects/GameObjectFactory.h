#pragma once
#include <memory>
#include "Squad.h"
#include "BuildingFactory.h"
class GameObjectFactory {
public:
	static std::shared_ptr<Squad> CreateSquad(int x, int y, int id) {
		return std::shared_ptr<Squad>(new Squad(x, y, id));
	}
	static std::shared_ptr<Building> CreateBuilding(int id, int health, int x, int y) {
		if (id == 0) 
			return std::shared_ptr<Building>(BuildingFactory::CreateCastle(health,x,y));
	}
};