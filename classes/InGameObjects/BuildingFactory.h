#pragma once
#include <memory>
#include "Castle.h"

class BuildingFactory {
public:
	static std::shared_ptr<Castle> CreateCastle(int health, int x, int y) {
		return std::shared_ptr <Castle>(new Castle(health, x, y));
	}
};
