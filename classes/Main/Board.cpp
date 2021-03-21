#include "Board.h"

//Board::Board(int width, int height) : width_(width), height_(height), board(std::vector<std::vector<GameObject*>>(width, std::vector<GameObject*>(height, nullptr))) {}

Board::Board(int width, int height) : width_(width), height_(height)
{
	board = std::vector<std::vector<GameObject*>>(width, std::vector<GameObject*>(height, nullptr));
}


Board::~Board()
{
	for (auto it : board)
	{
		for (auto it2 : it)
		{
			delete it2;
		}
	}
}


int Board::GetWidth()
{
	return width_;
}

int Board::GetHeight()
{
	return height_;
}

