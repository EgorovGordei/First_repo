#pragma once
#include "Building.h"
class Castle:public Building {
private:
	int id_ = 0;
	int max_health_ = 0;
public:
	Castle(int health, int x, int y): max_health_(health) {
		x_ = x;
		y_ = y;
		health_ = max_health_;
	}
	int GetBuildingId() override { return id_; }
	int GetMaxHealth() override  { return max_health_;  }
};