#pragma once
#include "GameObject.h"
class Building: public GameObject {
protected:
	int x_ = -1;
	int y_ = -1;
	int health_ = 0;
public:
	void ChangeHealth(int dx) {
		health_ = (health_ - dx > 0 ? health_ - dx : 0);
	}
	virtual int GetBuildingId() = 0;
	int Gethealth() {
		return health_;
	}
	virtual int GetMaxHealth() = 0;

	std::pair<int, int> GetCoordinates() {
		return std::make_pair(x_, y_);
	}
};