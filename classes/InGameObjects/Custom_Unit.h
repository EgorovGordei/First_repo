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
	CustomUnit(std::string name, int power, int health, int cost, int distance_of_attack, int distance_of_walk) :
		name_(name), max_power_(power), max_health_(health), cost_(cost), distance_of_walk_(distance_of_walk),
		distance_of_attack_(distance_of_attack) {
		universal_id++;
		id_ = universal_id;

	}
	CustomUnit(const CustomUnit& other);
	CustomUnit() {}
	int GetCost() { return cost_; }
	int GetDistanceOfAttack() { return distance_of_attack_; }
	int GetDistanceOfWalk() { return distance_of_walk_; }
	void ChangeHealth(int dx) {
		health_ = (health_ + dx > max_health_ ? max_health_ : health_ + dx);
	}
	void ChangePower(int dx) {
		power_ = (power_ + dx > max_power_ ? max_power_ : power_ + dx);
	}

	int GetId() { return id_; }
	int GetMaxHealth() override {
		return max_health_;
	}
	int GetMaxPower() override {
		return max_power_;
	}
};

CustomUnit::CustomUnit(const CustomUnit& other) :
	name_(other.name_), max_power_(other.max_power_), max_health_(other.max_health_), cost_(other.cost_),
	distance_of_walk_(other.distance_of_walk_), distance_of_attack_(other.distance_of_attack_), id_(other.id_) {}