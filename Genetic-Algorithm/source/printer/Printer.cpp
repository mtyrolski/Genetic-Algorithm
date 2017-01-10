#include "Printer.hpp"


Printer::Printer()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Printer::printMenu()
{
	setForegroundColor(COLOR::yellow);

}

void Printer::setForegroundColor(COLOR color)
{
	switch (color)
	{
		case COLOR::blue:
		{
			SetConsoleTextAttribute(hout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		}

		case COLOR::green:
		{
			SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		}

		case COLOR::red:
		{
			SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		}

		case COLOR::yellow:
		{
			SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		}
	}
}
