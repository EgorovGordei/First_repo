#pragma once
#include "Warrior.h"
#include <string>

class CustomUnit : public Warrior {
private:
	int id_ = -1;
	std::string name_ = "";
	int max_power_ = 0; // сила
	int max_health_ = 0; // здоровье
	int cost_ = 0; // стоимость 
	int distance_of_attack_ = 0; // дальность атаки
	int distance_of_walk_ = 0; // дальность ходьбы

public:
	CustomUnit(std::string name, int power, int health, int cost, int distance_of_attack, int distance_of_walk);
	CustomUnit(const CustomUnit& other);
	CustomUnit();
	int GetCost();
	int GetDistanceOfAttack();
	int GetDistanceOfWalk();
	void ChangeHealth(int dx);
	void ChangePower(int dx);

	int GetId();
	int GetMaxHealth() override;
	int GetMaxPower() override;
};

