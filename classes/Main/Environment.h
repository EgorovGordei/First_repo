#pragma once
#include <vector>
#include "Board.h"
#include "Level.h"

class Player
{
};

class Environment
{
private:
	std::vector<Player> players_;
	int turn_ = 0;
public:
	Level level;
	Board board;

	Environment(int screen_width, int screen_height);
};

