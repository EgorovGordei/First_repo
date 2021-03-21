#pragma once
class Warrior {
protected:
	static int universal_id;
	int power_ = 0;
	int health_ = 0;
public:
	int GetHealth();
	int GetPower();
	void DealDamage(int dx);
	void SetUniversalId();

	virtual void ChangeHealth(int dx) = 0;
	virtual void ChangePower(int dx) = 0;

	virtual int GetCost() = 0;
	virtual int GetMaxHealth() = 0;
	virtual int GetMaxPower() = 0;
	virtual int GetDistanceOfAttack() = 0;
	virtual int GetDistanceOfWalk() = 0;
	virtual int GetId() = 0;

	virtual ~Warrior();
};

