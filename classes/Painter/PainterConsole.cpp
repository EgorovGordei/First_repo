#include "PainterConsole.h"

void PainterConsole::cls()
{
	printf("\033[2J\033[1;1H");	
}

void PainterConsole::print(std::string text_to_print)
{
	printf((color_ + text_to_print).c_str());
}

void PainterConsole::flush()
{
	fflush(stdout);
}

void PainterConsole::set_red()
{
	color_ = "\033[0;31m";
}

void PainterConsole::set_white()
{
	color_ = "\033[0m";
}

void PainterConsole::set_green()
{
	color_ = "\033[0;32m";
}

