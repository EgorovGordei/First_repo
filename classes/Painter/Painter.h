#pragma once
#include <string>

class Painter
{
public:
	virtual ~Painter();

	virtual void cls() = 0;
	virtual void print(std::string to_print) = 0;
	virtual void flush() = 0;

	virtual void set_red() = 0;
	virtual void set_white() = 0;
};


