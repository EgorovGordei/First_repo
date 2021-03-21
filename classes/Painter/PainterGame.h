#pragma once 
#include "Painter.h"
#include "PainterFactory.h"
#include <memory>
#include <string>
#include "Board.h"
#include "Level.h"

class Menu;

class PainterGame
{
private:
	std::shared_ptr<Painter> painter_;
	Menu* menu_;
	int step_ = 0;
	int x_ = 0;
	int y_ = 0;
	int i_ = 0;
	Board& board_;
	Level& level_;
public:
	PainterGame(Menu* menu, Board& board, Level& level);
	void ClearScreen();

	void SetStep(int step);
	bool ProcessKey(char key);
};

//#include "Menu.h"

