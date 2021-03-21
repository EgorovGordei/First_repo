#include "WarriorFactory.h"


std::vector<CustomUnit> WarriorFactory::all_user_warriors;

std::shared_ptr<Archer> WarriorFactory::CreateArcher() {
	return std::shared_ptr<Archer>(new Archer());
}
std::shared_ptr<Swordsman> WarriorFactory::CreateSwordsman() {
	return std::shared_ptr<Swordsman>(new Swordsman());
}
std::shared_ptr<Cavalery> WarriorFactory::CreateCavalery() {
	return std::shared_ptr<Cavalery>(new Cavalery());
}
std::shared_ptr<CustomUnit> WarriorFactory::CreateCustomUnit(int id) { // if it can not be created, return nullptr
	if (id > (static_cast<int>(all_user_warriors.size()) - 2)) {
		return nullptr;
	}
	else {
		return std::shared_ptr<CustomUnit>(new CustomUnit(all_user_warriors[id - 2]));
	}
}
WarriorFactory::WarriorFactory(){}


