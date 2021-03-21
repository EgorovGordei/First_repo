#pragma once
#include "Army.h"
#include "PlayerBuildings.h"
//#include "Board.h"
//#include "Stats.h"
#include <map>

class Board;
class Stats;

class Player {
public:
	Army army;
	PlayerBuildings buildings;
	Player(bool id, Board& board);
	Player(Stats& stats, Board& board);
	bool MoveSquad(int squad_x, int squad_y, int to_x, int to_y); // �������������, ��� �� �� ������� �� ������ ����
	bool CreateSquad(int warrior_type, int squad_x, int squad_y);
	int GetMoney() { return money_; }
	bool AttackBySquad(int squad_id, int enemy_squad_id);
private:
	Board& board_;
	int money_ = 0;
	bool control_ = 0; // 0 if computer, 1 if human

};

#include "Board.h"
#include "Stats.h"

Player::Player(bool id, Board& board) : board_(board), control_(id) {}

Player::Player(Stats& stats, Board& board) : board_(board), control_(1) {}

bool Player::MoveSquad(int squad_x, int squad_y, int to_x, int to_y)
{
	auto it = army.squads.find(std::make_pair(squad_x, squad_y));
	return false;
}

bool Player::CreateSquad(int warrior_type, int squad_x, int squad_y)
{
	return false;
}

bool Player::AttackBySquad(int squad_id, int enemy_squad_id)
{
	return false;
}

