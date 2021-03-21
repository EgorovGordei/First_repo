#pragma once
#include "Warrior.h"
class Archer: public Warrior {
private:
	const int id_ = 0;
	const int max_power_ = 5;  // максимальное возможное значение силы
	const int max_health_ = 5; // максимальное возможное значение здоровья
	const int cost_ = 2; // стоимость лучника
	const int distance_of_attack_ = 2; // дальность атаки
	const int distance_of_walk_ = 1; // дальность ходьбы

public:
	Archer() {
		health_ = max_health_;
		power_ = max_power_;
	}
	int GetCost() { return cost_; }
	int GetDistanceOfAttack() override { return distance_of_attack_; }
	int GetDistanceOfWalk() override { return distance_of_walk_; }
	void ChangeHealth(int dx) override {
		health_ = (health_ + dx > max_health_ ? max_health_ : health_ + dx);
		health_ = (health_ < 0 ? 0 : health_);
	}
	void ChangePower(int dx)  override{
		power_ = (power_ + dx > max_power_ ? max_power_ : power_ + dx);
	}
	int GetId() override { return id_; }
	int GetMaxHealth() override {
		return max_health_;
	}
	int GetMaxPower() override {
		return max_power_;
	}
};