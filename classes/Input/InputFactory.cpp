#include "InputFactory.h"
#include "InputKeyboard.h"

[[nodiscard]] std::unique_ptr<InputController> InputFactory::GetInputController()
{
	return std::unique_ptr<InputController>(new InputKeyboard());
}

