#pragma once
#include "Warrior.h"
class Archer: public Warrior {
private:
	const int id_ = 0;
	const int max_power_ = 5;  // ������������ ��������� �������� ����
	const int max_health_ = 5; // ������������ ��������� �������� ��������
	const int cost_ = 2; // ��������� �������
	const int distance_of_attack_ = 2; // ��������� �����
	const int distance_of_walk_ = 1; // ��������� ������

public:
	Archer();
	int GetCost();
	int GetDistanceOfAttack() override;
	int GetDistanceOfWalk() override;
	void ChangeHealth(int dx) override;
	void ChangePower(int dx)  override;
	int GetId() override ;
	int GetMaxHealth() override;
	int GetMaxPower() override;
};
