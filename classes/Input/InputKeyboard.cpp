#include "InputKeyboard.h"

int InputKeyboard::GetLastPressedKey()
{
	if (!_kbhit()) return 0;
	int key_pressed = getchar();
	return key_pressed;	
}

