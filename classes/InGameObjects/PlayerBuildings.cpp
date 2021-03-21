#include "PlayerBuildings.h"

void PlayerBuildings::AddBuilding(int health, int x, int y) {
	if (buildings.find(std::make_pair(x, y)) == buildings.end()) {
		buildings[std::make_pair(x, y)] = BuildingFactory::CreateCastle(health, x, y);
	}
}
void PlayerBuildings::RemoveBuilding(int x, int y) {
	auto it = buildings.find(std::make_pair(x, y));
	if (it != buildings.end()) {
		buildings.erase(it);
	}
}

std::map<std::pair<int, int>, std::shared_ptr<Building>> PlayerBuildings::buildings;
