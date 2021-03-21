#pragma once
#include "Warrior.h"
class Swordsman : public Warrior
{
private:
	const int id_ = 1;
	const int max_power_ = 7;  // максимальное возможное значение силы
	const int max_health_ = 5; // максимальное возможное значение здоровья
	const int cost_ = 1; // стоимость мечника
	const int distance_of_attack_ = 1; // дальность атаки
	const int distance_of_walk_ = 1; // дальность ходьбы

public:
	Swordsman() {
		health_ = max_health_;
		power_ = max_power_;
	}
	int GetCost() { return cost_; }
	int GetDistanceOfAttack() { return distance_of_attack_; }
	int GetDistanceOfWalk() { return distance_of_walk_; }
	void ChangeHealth(int dx) {
		health_ = (health_ + dx > max_health_ ? max_health_ : health_ + dx);
		health_ = (health_ < 0 ? 0 : health_);
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

