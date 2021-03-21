#include "Shop.h"
#include "InputKeyboard.h"
#include "InputFactory.h"
#include "PainterShop.h"

Shop::Shop(Menu* menu) : menu_(menu), stats_(menu->stats) {}

void Shop::MainLoop()
{
	// get new PainterMenu
	PainterShop PS(menu_);
	PS.SetStep(step);
	PS.ClearScreen();
	while (true)
	{
		// get new pressed key
		int pressed_key = 0;
		pressed_key = menu_->IC.get()->GetLastPressedKey();
		if (pressed_key)
		{
			bool b = PS.ProcessKey(pressed_key);
			if (!b) break;
		}
		usleep(100);
	}
	PS.ClearScreen();
}

