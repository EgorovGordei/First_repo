#pragma once

#include "Cell.h"
#include <string>
#include <vector>

class Level
{
private:
	std::vector<std::vector<Cell>> cells_;
	int width_ = 0;
	int height_ = 0;
	std::string name_;
	int amount_of_players_ = 2;
	std::vector<std::vector<std::pair<int, int>>> castle_start_positions_;
	
	bool LoadLevel(std::string& name);
public:
	const std::string PATH_TO_LEVELS = "./data/levels.txt";

	Level(std::string name);
	std::vector<Cell>& operator[](unsigned i);
	int GetWidth();
	int GetHeight();
	int GetAmountOfPlayers();
	std::string GetName();
	void SetName(std::string name);

	std::string ToString();
};


