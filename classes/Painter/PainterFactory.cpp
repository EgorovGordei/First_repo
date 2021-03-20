#include "PainterFactory.h"

std::unique_ptr<Painter> PainterFactory::GetPainter()
{
	return std::unique_ptr<Painter>(new PainterConsole());
}

