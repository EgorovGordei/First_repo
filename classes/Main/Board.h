#pragma once
#include <vector>

// include GameObject
class GameObject
{
};

class Board
{
private:
	int width_ = 0;
	int height_ = 0;
public:
	std::vector<std::vector<GameObject*>> board;

	Board(int width, int height);
	~Board();
	Board(const Board&) = delete;
	Board(Board&&) = delete;
	Board& operator=(const Board&) = delete;
	Board& operator=(Board&&) = delete;

	int GetWidth();
	int GetHeight();
};

