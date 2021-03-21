#include "PainterShop.h"

PainterShop::PainterShop(Menu* menu): menu_(menu)
{
	painter_ = PainterFactory::GetPainter();
	ProcessKey(0);
}

void PainterShop::ClearScreen()
{
	painter_->cls();
}

bool PainterShop::ProcessKey(char key)
{
	if (step_ == 0)
	{
		// quit
		if (key == 'q') return false;

		painter_->cls();
		painter_->print("Press Q to exit\nI'm a shop class!\n");
		painter_->flush();
	}
	return true;
}

void PainterShop::SetStep(int step)
{
	if (step != step_) i_ = 0;
	step_ = step;
}

