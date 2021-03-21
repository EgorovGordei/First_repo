#include "Archer.h"

Archer::Archer() 
{
	health_ = max_health_;
	power_ = max_power_;
}

int Archer::GetCost() { return cost_; }
int Archer::GetDistanceOfAttack() { return distance_of_attack_; }
int Archer::GetDistanceOfWalk() { return distance_of_walk_; }
void Archer::ChangeHealth(int dx) 
{
	health_ = (health_ + dx > max_health_ ? max_health_ : health_ + dx);
	health_ = (health_ < 0 ? 0 : health_);
}
void Archer::ChangePower(int dx) 
{
	power_ = (power_ + dx > max_power_ ? max_power_ : power_ + dx);
}
int Archer::GetId() { return id_; }
int Archer::GetMaxHealth() {
	return max_health_;
}
int Archer::GetMaxPower() {
	return max_power_;
}

