#include "Warrior.h"


int Warrior::GetHealth() { return health_; }
int Warrior::GetPower() { return power_; }
void Warrior::DealDamage(int dx) {
	health_ = (health_ - dx > 0 ? health_ -dx: 0);
}
void Warrior::SetUniversalId() {
	universal_id = 2;
}
Warrior::~Warrior() {}


int Warrior::universal_id;

