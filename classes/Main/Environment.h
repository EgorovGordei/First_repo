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
	Board board;
	Level level;

	Environment(int screen_width, int screen_height);
};

