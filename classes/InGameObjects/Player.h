#pragma once
#include "Army.h"
#include "PlayerBuildings.h"
class Player {
public:
	Army army;
	PlayerBuildings buildings;
	Player(bool id);
	void MoveSquad(int squad_x, int squad_y, int to_x, int to_y); // гарантируется, что мы не выходим за клетки поля
	void CreateSquad(int warrior_type, int squad_x, int squad_y);
	int GetMoney() { return money_; }
	void AttackBySquad(int squad_id, int enemy_squag_id);
private:
	int money_ = 0;
	bool control_ = 0; // 0 if computer, 1 if human

};
