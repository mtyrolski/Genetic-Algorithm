#include "printer/Printer.hpp"
#include "simulator/Simulator.hpp"
#include "program/Program.hpp"
#include <conio.h>
#include <iostream>

int main()
{
	Printer printer;
	Simulator simulator;
	Program program;

	while (program.running())
	{
		if (kbhit)
		{
			unsigned char mark = getch();
			switch (mark)
			{
			case 1: printer.clear();
			case 2: program.stop(); break;
			}
		}
	}
	

	return 0;
}