#include "printer/Printer.hpp"
#include "simulator/Simulator.hpp"
#include "program/Program.hpp"

#include <conio.h>
#include <iostream>

#pragma warning(disable : 4996)

int main()
{
	Printer printer;
	Simulator simulator;
	Program program(printer);

	printer.print("source/data/menu.txt");

	while (program.running())
	{
		if (kbhit)
			program.takeAction(getch());
	}

	

	return 0;
}