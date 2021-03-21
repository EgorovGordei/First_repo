#include "Player.h"


Player::Player(bool id, Board& board) : board_(board), control_(id) {}

Player::Player(Stats& stats, Board& board) : board_(board), control_(1) {}

bool Player::MoveSquad(int squad_x, int squad_y, int to_x, int to_y)
{
	//auto it = army.squads.find(std::make_pair(squad_x, squad_y));
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

