#include "PainterGame.h"

PainterGame::PainterGame(Menu* menu, Board& board, Level& level): menu_(menu), board_(board), level_(level)
{
	painter_ = PainterFactory::GetPainter();
	ProcessKey(0);
}

void PainterGame::ClearScreen()
{
	painter_->cls();
}

bool PainterGame::ProcessKey(char key)
{
	if (step_ == 0)
	{
		// quit
		if (key == 'q') return false;

		if (key == 65) --y_;
		if (key == 66) ++y_;
		if (key == 68) --x_;
		if (key == 67) ++x_;
		if (y_ < 0) y_ = 0;
		if (y_ >= board_.GetHeight()) y_ = board_.GetHeight() - 1;
		if (x_ < 0) x_ = 0;
		if (x_ >= board_.GetWidth()) x_ = board_.GetWidth() - 1;

		painter_->cls();	
		painter_->print("Press Q to exit\nI'm a game class!\n");
		//int x = 0;
		for (int y = 0; y < board_.GetHeight(); ++y)
		{
			//int y = 0;
			for (int x = 0; x < board_.GetWidth(); ++x)
			{
				if (level_[x][y].i == 1)
					painter_->set_green();

				if (x_ == x && y_ == y)
					painter_->set_red();
				
				if (board_.board[x][y] == nullptr)
					painter_->print("0");
				else
					painter_->print("!");

				painter_->set_white();
			}
			painter_->print("\n");
		}	
		painter_->flush();
	}
	return true;
}

void PainterGame::SetStep(int step)
{
	if (step != step_) i_ = 0;
	step_ = step;
}

