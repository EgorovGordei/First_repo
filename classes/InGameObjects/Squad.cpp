#include "Squad.h"


std::pair<int, int> Squad::getCoordinates() {
	return std::make_pair(x_, y_);
}
std::vector<std::shared_ptr<Warrior>> Squad::GetWarriors() { return warriors; } // return vector of warriors in this squad
void Squad::SetCoordinates(int x, int y) {
	x_ = x;
	y_ = y;
}
bool Squad::IsEmpty() {
	return warriors.empty();
}
void Squad::AddWarrior() {
	addWarriorId(warrior_id_);
}

inline void Squad::addWarriorId(int id)
{
	if (id == 0) {
		warriors.push_back(WarriorFactory::CreateArcher());
		health_ += warriors.back()->GetHealth();
		power_ += warriors.back()->GetPower();
	}
	if (id == 1) {
		warriors.push_back(WarriorFactory::CreateSwordsman());
		health_ += warriors.back()->GetHealth();
		power_ += warriors.back()->GetPower();
	}
	if (id == 2) {
		warriors.push_back(WarriorFactory::CreateCavalery());
		health_ += warriors.back()->GetHealth();
		power_ += warriors.back()->GetPower();
	}

	if (id > 2) {
		std::shared_ptr<Warrior> warrior = WarriorFactory::CreateCustomUnit(id);
		if (warrior != nullptr) {
			warriors.push_back(std::move(warrior));
			health_ += warriors.back()->GetHealth();
			power_ += warriors.back()->GetPower();
		}
	}

}
inline void Squad::removeWarrior()
{
		if (!IsEmpty()) {
			health_ -= warriors.back()->GetHealth();
			power_ -= warriors.back()->GetPower();
			warriors.pop_back();
		}
}
inline void Squad::removeAll()
{

	warriors.clear();
	health_ = 0;
	power_ = 0;
}
inline void Squad::ReduceHealth(int dx)
{
	if (health_ <= dx) {
		removeAll();
	}
	else {
		int new_health = health_ - dx;
		while (health_ - warriors.back()->GetHealth() >= new_health) {
			removeWarrior();
		}
		warriors.back()->ChangeHealth(-(health_ - new_health));
		health_ = new_health;
	}
}
inline int Squad::GetDistanceOfWalk()
{
	if (!IsEmpty()) {
		return warriors[0]->GetDistanceOfWalk();
	}
	else {
		return -1;
	}
}
inline int Squad::GetDistanceOfAttack()
{
	if (!IsEmpty()) {
		return warriors[0]->GetDistanceOfAttack();
	}
	else {
		return -1;
	}
}
Squad::Squad(int warrior_id, int x, int y) :warrior_id_(warrior_id), x_(x), y_(y) {
	addWarriorId(warrior_id);	
}

inline void Squad::Move(int x, int y)
{
	if (sqrt((x - x_) * (x - x_) + (y - y_) * (y - y)) <= double(GetDistanceOfWalk())) {
		SetCoordinates(x,y);
	}
}

