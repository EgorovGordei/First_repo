#include "PainterFactory.h"

std::shared_ptr<Painter> PainterFactory::last_painter_ = nullptr;

std::shared_ptr<Painter> PainterFactory::GetPainter()
{
	if (last_painter_.get() == nullptr) last_painter_ = std::shared_ptr<Painter>(new PainterConsole());
	return last_painter_;
}

