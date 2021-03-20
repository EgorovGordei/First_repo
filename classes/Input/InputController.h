#pragma once

// interface, provides access to last pressed key
class InputController
{
public:
	// find and return last pressed key
	virtual int GetLastPressedKey() = 0;
};

