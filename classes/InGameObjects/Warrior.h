#pragma once
class Warrior {
protected:
	static int universal_id;
	int power_ = 0;
	int health_ = 0;
public:
	int GetHealth() { return health_; }
	int GetPower() { return power_; }
	void DealDamage() {
		health_ = (health_ > 0 ? health_ : 0);
	}
	void SetUniversalId() {
		universal_id = 2;
	}

	virtual void ChangeHealth(int dx) = 0;
	virtual void ChangePower(int dx) = 0;

	virtual int GetCost() = 0;
	virtual int GetMaxHealth() = 0;
	virtual int GetMaxPower() = 0;
	virtual int GetDistanceOfAttack() = 0;
	virtual int GetDistanceOfWalk() = 0;
	virtual int GetId() = 0;

	virtual ~Warrior() {}
};