#pragma once

#include "InputController.h"
#include "InputFactory.h"
#include "Stats.h"

#include <vector>

class Menu
{
private:
	// step 0 - creating player
	// step 1 - choosing menu option
	int step = 0;
public:
	const int START_MONEY = 10;
	const std::vector<int> START_UNITS_IDS = { 0, 1, 2 };

	Stats stats;
	Menu();
	void MainLoop();
};

