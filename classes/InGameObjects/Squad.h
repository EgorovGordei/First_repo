#pragma once
#include "Warrior.h"
#include "GameObject.h"
#include "WarriorFactory.h"
#include <vector>
#include <utility>
#include <memory>
#include <math.h>

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
	std::pair<int, int> getCoordinates();
	void ReduceHealth( int dx);
	std::vector<std::shared_ptr<Warrior>> GetWarriors(); // return vector of warriors in this squad
	int GetDistanceOfWalk();
	int GetDistanceOfAttack();
	void SetCoordinates(int x, int y);
	Squad(int warrior_id, int x, int y);
	bool IsEmpty();

	void AddWarrior();
	void Move(int x, int y);
};

