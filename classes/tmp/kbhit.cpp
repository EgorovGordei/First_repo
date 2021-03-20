#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <ctime>
//#include <stropts.h>


int _kbhit()
{
	static const int STDIN = 0;
	static bool initialized = false;
	
	if (!initialized)
	{
		termios term;
		tcgetattr(STDIN, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN, TCSANOW, &term);
		setbuf(stdin, NULL);
		initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN, FIONREAD, &bytesWaiting);
	return bytesWaiting;
}

int main()
{
	while (true)
	{
		int i = 0;
		while (true)
		{
			if (_kbhit()) break;

			i = (i + 1) % 2;

			//printf("\033[2J\033[1;1H");
			fflush(stdout);
			//setvbuf(stdout, NULL, _IONBF, 0);
			//if (i == 0)
			//	printf(".");
			//else
			//	printf(",");
			////sleep(100);
		}
		printf("Char?: ");
		char c = getchar();
		printf("%d", c);
		printf("\n");
		if (c == 'q') break;
	}
}
