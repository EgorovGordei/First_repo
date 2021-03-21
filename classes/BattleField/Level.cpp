#include <Level.h>


Level::Level(std::string name)
{
	LoadLevel(name);	
}

bool Level::LoadLevel(std::string& name)
{
	// need to download
	//
	width_ = 5;
	height_ = 10;
	name_ = "nothing";
	amount_of_players_ = 2;
	castle_start_positions_ = { {std::make_pair(1,1)},{std::make_pair(3, 8)}};
	cells_ = std::vector<std::vector<Cell>>(width_, std::vector<Cell>(height_, Cell(0)));
	for (int i = 0; i < width_; ++i)
	{
		for (int j = 0; j < height_; ++j)
		{
			if (i <= 3 && j <= 4) cells_[i][j] = Cell(1);
		}
	}
	return false;
}

std::vector<Cell>& Level::operator[](unsigned i)
{
	return cells_[i];
}

int Level::GetWidth()
{
	return width_;
}

int Level::GetHeight()
{
	return height_;
}

int Level::GetAmountOfPlayers()
{
	return amount_of_players_; 
}

std::string Level::GetName()
{
	return name_;
}
void Level::SetName(std::string name)
{
	name_ = name;
}
std::string Level::ToString()
{
	return "still_nothing_yet;";
}




