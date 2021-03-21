#pragma once
#include "GameObject.h"
#include <utility>

class Building: public GameObject {
protected:
	int x_ = -1;
	int y_ = -1;
	int health_ = 0;
public:
	void ChangeHealth(int dx);
	virtual int GetBuildingId() = 0;
	int Gethealth();
	virtual int GetMaxHealth() = 0;

	std::pair<int, int> GetCoordinates();
};
