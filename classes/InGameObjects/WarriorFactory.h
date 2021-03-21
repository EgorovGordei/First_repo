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

	static std::shared_ptr<Archer> CreateArcher();
	static std::shared_ptr<Swordsman> CreateSwordsman();
	static std::shared_ptr<Cavalery> CreateCavalery();
	static std::shared_ptr<CustomUnit> CreateCustomUnit(int id);
	WarriorFactory();
};



