#pragma once
#include <vector>
#include "GameObjectFactory.h"
#include <memory>
#include <map>
class Army {
public:
	static std::map<std::pair<int, int>, std::shared_ptr<Squad>> squads;
	void CreateNewSquad(int squad_x, int squad_y, int warrior_type);
	void RemoveExistingSquad(int squad_x, int squad_y);
};

std::map<std::pair<int, int>, std::shared_ptr<Squad>> Army::squads;

void Army::CreateNewSquad(int squad_x, int squad_y, int warrior_type) {

	if (squads.find(std::make_pair(squad_x, squad_y)) == squads.end()){
		squads[std::make_pair(squad_x, squad_y)] = std::shared_ptr<Squad>(GameObjectFactory::CreateSquad(squad_x, squad_y, warrior_type));
	}

}

inline void Army::RemoveExistingSquad(int squad_x, int squad_y)
{
	auto it = squads.find(std::make_pair(squad_x, squad_y));
	if (it != squads.end()) {
		squads.erase(it);
	}
}
