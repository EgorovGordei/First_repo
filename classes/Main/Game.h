#pragma once

#include "InputController.h"
#include "InputFactory.h"
#include "Stats.h"
#include "Environment.h"

#include <vector>

class Menu;

class Game
{
private:
	// step 0 - nothing_yet
	int step = 0;
	Menu* menu_;
	Stats& stats_;
	Environment environment_;
public:
	Game(Menu* menu_);
	void MainLoop();
};

