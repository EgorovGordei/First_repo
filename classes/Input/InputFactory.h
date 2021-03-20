#pragma once

#include "InputKeyboard.h"
#include <memory>

class InputFactory
{
public:
	[[nodiscard]] static std::unique_ptr<InputController> GetInputController();
};
