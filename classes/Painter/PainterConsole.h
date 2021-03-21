#pragma once

#include "Painter.h"
#include <unistd.h>
#include <cstdio>
#include <string>

class PainterConsole: public Painter
{
private:
	std::string color_ = "\033[0m";
public:
	void cls() override;
	void print(std::string text_to_print) override;
	void flush() override;

	void set_red() override;
	void set_white() override;
	void set_green() override;
};


