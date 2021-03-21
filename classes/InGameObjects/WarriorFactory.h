#pragma once
#include "Archer.h"
#include "Swordsman.h"
#include "Cavalery.h"
#include "Custom_Unit.h"
#include <vector>
#include <memory>
class WarriorFactory {

public:
	static std::vector<CustomUnit> all_user_warriors;

	static std::shared_ptr<Archer> CreateArcher() {
		return std::shared_ptr<Archer>(new Archer());
	}
	static std::shared_ptr<Swordsman> CreateSwordsman() {
		return std::shared_ptr<Swordsman>(new Swordsman());
	}
	static std::shared_ptr<Cavalery> CreateCavalery() {
		return std::shared_ptr<Cavalery>(new Cavalery());
	}
	static std::shared_ptr<CustomUnit> CreateCustomUnit(int id) { // if it can not be created, return nullptr
		if (id > (all_user_warriors.size() - 2)) return nullptr;

		return std::shared_ptr<CustomUnit>( new CustomUnit(all_user_warriors[id-2]));

	}

	WarriorFactory(){}
};
std::vector<CustomUnit> WarriorFactory::all_user_warriors;


