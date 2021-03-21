#pragma once 
#include "Painter.h"
#include "PainterFactory.h"
#include <memory>
#include <string>

class Menu;

class PainterShop
{
private:
	std::shared_ptr<Painter> painter_;
	Menu* menu_;
	int step_ = 0;
	int i_ = 0;
public:
	PainterShop(Menu* menu);
	void ClearScreen();

	void SetStep(int step);
	bool ProcessKey(char key);
};

#include "Menu.h"

