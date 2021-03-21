#pragma once
#include <memory>
#include "PainterMenu.h"
#include "Painter.h"
#include "PainterConsole.h"

class PainterFactory
{
private:
	static std::shared_ptr<Painter> last_painter_;
public:
	static std::shared_ptr<Painter> GetPainter();
};


