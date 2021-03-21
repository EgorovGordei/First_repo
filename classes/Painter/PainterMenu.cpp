#include "PainterMenu.h"

PainterMenu::PainterMenu(Menu* menu): menu_(menu)
{
	painter_ = PainterFactory::GetPainter();
	ProcessKey(0);
}

void PainterMenu::ClearScreen()
{
	painter_->cls();
}

bool PainterMenu::ProcessKey(char key)
{
	if (step_ == 0)
	{
		// create new player
		if (i_ == 0)
		{
			val_ = "";	
			i_ = 1;
		}
		if (key == '\n')
		{
			menu_->stats.CreateNewPlayer(val_, menu_->START_MONEY, menu_->START_UNITS_IDS);
			step_ = 1;
			i_ = 0;
			key = 0;
		}
		else
		{
			if (key != 0) val_ += key;
			painter_->cls();
			painter_->print("Input your name: " + val_ + ";\n");
			painter_->print(std::to_string(key));
			painter_->flush();
		}
	}
	if (step_ == 1)
	{
		// quit
		if (key == 'q') return false;

		// option is chosed
		if (key == '\n')
		{
			if (i_ == 0)
				step_ = 2;
			if (i_ == 1)
				step_ = 3;
			if (i_ == 2)
				step_ = 4;
		}
		else
		{
			// choosing option
			if (key == 65) --i_;
			if (key == 66) ++i_;
			if (i_ > 2) i_ = 2;
			if (i_ < 0) i_ = 0;

			painter_->cls();
			painter_->print("Press Q to exit\n\nHello, Commander!\n");
			painter_->print("Name: " + menu_->stats.GetName() + "\n");
			painter_->print("Money: " + std::to_string(menu_->stats.GetMoney()) + "\n");
			painter_->print("\nChoose one of options using arrows:\n");
			if (i_ == 0) painter_->set_red();
			painter_->print("Play\n");
			if (i_ == 0) painter_->set_white();
			if (i_ == 1) painter_->set_red();
			painter_->print("Shop\n");
			if (i_ == 1) painter_->set_white();
			if (i_ == 2) painter_->set_red();
			painter_->print("Something else\n");
			if (i_ == 2) painter_->set_white();
			painter_->flush();
		}
	}
	if (step_ == 2)
	{
		if (key == 'q')
		{
			step_ = 1;
			i_ = 0;
			ProcessKey(0);
		}
		else
		{
			painter_->cls();
			painter_->print("Press Q to return back\n");
			painter_->set_red();
			painter_->print("/\\/\\\n\\  /\n \\/ \n");
			painter_->set_white();
			painter_->print("I must call Game class, but I haven't made it yet :)");
			painter_->flush();
		}
	}
	if (step_ == 3)
	{
		menu_->shop.MainLoop();
		step_ = 1;
		i_ = 0;
		ProcessKey(0);
	}
	if (step_ == 4)
	{
		if (key == 'q')
		{
			step_ = 1;
			i_ = 0;
			ProcessKey(0);
		}
		else
		{
			painter_->cls();
			painter_->print("Press Q to return back\n");
			painter_->set_white();
			painter_->print("/\\/\\\n\\  /\n \\/ \n");
			painter_->set_red();
			painter_->print("It's just for something in future");
			painter_->set_white();
			painter_->flush();
		}
	}
	return true;
}

void PainterMenu::SetStep(int step)
{
	if (step != step_) i_ = 0;
	step_ = step;
}

