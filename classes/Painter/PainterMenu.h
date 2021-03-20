#pragma once 
#include "Painter.h"
#include "PainterFactory.h"
#include <memory>
#include <string>

class Menu;

class PainterMenu
{
private:
	std::unique_ptr<Painter> painter_;
	Menu* menu_;
	int step_ = 0;
	int i_ = 0;
	std::string val_;
	std::string player_name_;
public:
	PainterMenu(Menu* menu);
	void ClearScreen();

	void SetStep(int step);
	bool ProcessKey(char key);
};

#include "Menu.h"

