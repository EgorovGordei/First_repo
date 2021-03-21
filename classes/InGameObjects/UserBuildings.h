#pragma once
#include "Building.h"
#include <vector>
#include <memory>
class Buildings {
private:
	std::vector<std::unique_ptr<Building>> buildings_;
};
