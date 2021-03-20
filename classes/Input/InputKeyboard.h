#pragma once

#include "InputController.h"
#include "kbhit.h"

// class, provides access to last pressed key on the keyboard
class InputKeyboard: public InputController
{
public:
	// return 0 if nothing pressed, else key code
	int GetLastPressedKey() override;
};

