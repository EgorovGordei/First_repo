//#include "conio.h"
//#include <iostream>

#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
//#include <stropts.h>


int IfSomethingPressed()
{
	timeval timeout;
	fd_set rdset;

	FD_ZERO(&rdset);
	FD_SET(0, &rdset);
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;

	return select(0 + 1, &rdset, NULL, NULL, &timeout);
}

int main()
{
	while (true)
	{
		int res = IfSomethingPressed();
		if (res) 
			break;
		printf(".");
	}
	printf("!\n");
}
