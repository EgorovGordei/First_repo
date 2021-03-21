#pragma once
#include <vector>
#include "GameObjectFactory.h"
#include <memory>
#include <map>

class Army {
public:
	static std::map<std::pair<int, int>, std::shared_ptr<Squad>> squads;
	std::shared_ptr<Squad> CreateNewSquad(int squad_x, int squad_y, int warrior_type);
	void RemoveExistingSquad(int squad_x, int squad_y);
};


