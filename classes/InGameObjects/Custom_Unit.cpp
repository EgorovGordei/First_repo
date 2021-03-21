#include "Custom_Unit.h"


CustomUnit::CustomUnit(std::string name, int power, int health, int cost, int distance_of_attack, int distance_of_walk) :
	name_(name), max_power_(power), max_health_(health), cost_(cost), distance_of_walk_(distance_of_walk),
	distance_of_attack_(distance_of_attack) {
	universal_id++;
	id_ = universal_id;
}

CustomUnit::CustomUnit() {}
int CustomUnit::GetCost() { return cost_; }
int CustomUnit::GetDistanceOfAttack() { return distance_of_attack_; }
int CustomUnit::GetDistanceOfWalk() { return distance_of_walk_; }
void CustomUnit::ChangeHealth(int dx) {
	health_ = (health_ + dx > max_health_ ? max_health_ : health_ + dx);
	health_ = (health_ < 0 ? 0 : health_);
}
void CustomUnit::ChangePower(int dx) {
	power_ = (power_ + dx > max_power_ ? max_power_ : power_ + dx);
	power_ = (power_ < 0 ? 0 : power_);
}

int CustomUnit::GetId() { return id_; }
int CustomUnit::GetMaxHealth() {
	return max_health_;
}
int CustomUnit::GetMaxPower() {
	return max_power_;
}


CustomUnit::CustomUnit(const CustomUnit& other) :
	name_(other.name_), max_power_(other.max_power_), max_health_(other.max_health_), cost_(other.cost_),
	distance_of_walk_(other.distance_of_walk_), distance_of_attack_(other.distance_of_attack_), id_(other.id_) {}
