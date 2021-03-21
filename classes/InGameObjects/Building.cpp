#include "Building.h"


void Building::ChangeHealth(int dx) 
{
	health_ = (health_ - dx > 0 ? health_ - dx : 0);
}

int Building::Gethealth() 
{
	return health_;
}

std::pair<int, int> Building::GetCoordinates() {
	return std::make_pair(x_, y_);
}

