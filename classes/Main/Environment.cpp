#include "Environment.h"


Environment::Environment(int screen_width, int screen_height, Stats& stats) : level(""), board(level.GetWidth(), level.GetHeight()), stats(stats)
{
	players_.push_back(Player(stats, board));
	for (int i = 1; i < level.GetAmountOfPlayers(); ++i)
	{
		players_.push_back(Player(0, board));
	}
}


