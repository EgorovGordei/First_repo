#pragma once
#include "Building.h"
#include "BuildingFactory.h"
#include <map>
#include <memory>

class PlayerBuildings {
public:
	void AddBuilding(int health, int x, int y);
       
	void RemoveBuilding(int x, int y);
       
	static std::map<std::pair<int, int>, std::shared_ptr<Building>> buildings;
};

