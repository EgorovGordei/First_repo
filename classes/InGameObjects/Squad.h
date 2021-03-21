#pragma once
#include "Warrior.h"
#include "GameObject.h"
#include "WarriorFactory.h"
#include <vector>
#include <utility>
#include <memory>
class Squad: public GameObject {
private:
	int warrior_id_ = -1; // id войнов, состоящих в этом отряде
	std::vector<std::shared_ptr<Warrior>> warriors;
	int health_ = 0;// здоровье отряда
	int power_ = 0; //сила отряда
	int x_ = -1;
	int y_ = -1;
	void addWarriorId(int id); // add warrior with id -> id
	void removeWarrior();
	void removeAll();
public:
	std::pair<int, int> getCoordinates() {
		return std::make_pair(x_, y_);
	}
	void ReduceHealth( int dx);
	std::vector<std::shared_ptr<Warrior>> GetWarriors() { return warriors; } // return vector of warriors in this squad
	int GetDistanceOfWalk();
	int GetDistanceOfAttack();
	void SetCoordinates(int x, int y) {
		x_ = x;
		y_ = y;
	}
	Squad(int warrior_id, int x, int y);
	bool IsEmpty() {
		return warriors.empty();
	}

	void AddWarrior() {
		addWarriorId(warrior_id_);
	}
	void Move(int x, int y);
};
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

