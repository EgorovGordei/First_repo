#include "GameObjectFactory.h"

std::shared_ptr<Squad> GameObjectFactory::CreateSquad(int x, int y, int id) {
	return std::shared_ptr<Squad>(new Squad(x, y, id));
}
std::shared_ptr<Building> GameObjectFactory::CreateBuilding(int id, int health, int x, int y) {
	if (id == 0) 
		return std::shared_ptr<Building>(BuildingFactory::CreateCastle(health,x,y));
	return std::shared_ptr<Building>(BuildingFactory::CreateCastle(health,x,y));
}

