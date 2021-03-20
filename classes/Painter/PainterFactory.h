#pragma once
#include <memory>
#include "PainterMenu.h"
#include "Painter.h"
#include "PainterConsole.h"

class PainterFactory
{
public:
	static std::unique_ptr<Painter> GetPainter();
};


