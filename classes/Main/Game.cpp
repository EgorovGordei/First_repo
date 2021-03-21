#include "Game.h"
#include "InputKeyboard.h"
#include "InputFactory.h"
#include "PainterGame.h"

Game::Game(Menu* menu) : menu_(menu), stats_(menu->stats), environment_(10, 5, stats_) {}

void Game::MainLoop()
{
	// get new PainterMenu
	PainterGame PG(menu_, environment_.board, environment_.level);
	PG.SetStep(step);
	PG.ClearScreen();
	while (true)
	{
		// get new pressed key
		int pressed_key = 0;
		pressed_key = menu_->IC.get()->GetLastPressedKey();
		if (pressed_key)
		{
			bool b = PG.ProcessKey(pressed_key);
			if (!b) break;
		}
		usleep(100);
	}
	PG.ClearScreen();
}

