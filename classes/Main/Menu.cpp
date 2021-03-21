#include "Menu.h"
#include "InputKeyboard.h"
#include "InputFactory.h"
#include "PainterMenu.h"

Menu::Menu() : IC(InputFactory::GetInputController()), shop(this), game(this) 
{
	bool b = stats.LoadLastPlayer();
	// no need to create new player
	if (b) step = 1;
}

void Menu::MainLoop()
{
	// get new PainterMenu
	PainterMenu PM(this);
	PM.SetStep(step);
	while (true)
	{
		// get new pressed key
		int pressed_key = 0;
		pressed_key = IC.get()->GetLastPressedKey();
		if (pressed_key)
		{
			bool b = PM.ProcessKey(pressed_key);
			if (!b) break;
		}
		usleep(100);
	}
	PM.ClearScreen();
}

