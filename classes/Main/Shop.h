#pragma once

#include "InputController.h"
#include "InputFactory.h"
#include "Stats.h"

#include <vector>

class Menu;

class Shop
{
private:
	// step 0 - nothing_yet
	int step = 0;
	Menu* menu_;
	Stats& stats_;
public:
	Shop(Menu* menu_);
	void MainLoop();
};

