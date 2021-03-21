#pragma once
//#include "Army.h"
//#include "PlayerBuildings.h"
#include "Board.h"
#include "Stats.h"
#include <map>

class Player {
public:
//	Army army;
//	PlayerBuildings buildings;
	Player(bool id, Board& board);
	Player(Stats& stats, Board& board);
	bool MoveSquad(int squad_x, int squad_y, int to_x, int to_y); // гарантируется, что мы не выходим за клетки поля
	bool CreateSquad(int warrior_type, int squad_x, int squad_y);
	int GetMoney() { return money_; }
	bool AttackBySquad(int squad_id, int enemy_squad_id);
private:
	Board& board_;
	int money_ = 0;
	bool control_ = 0; // 0 if computer, 1 if human

};

