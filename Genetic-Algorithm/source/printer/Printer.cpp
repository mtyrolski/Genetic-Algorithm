#include "Printer.hpp"


Printer::Printer()
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Printer::printMenu()
{
	std::ifstream ifile(constants::path::menu, std::ifstream::in);

	std::string line;

	while (std::getline(ifile, line))
	{
		if (line[0] == '#')
			matchColor(line.substr(1,line.size()-1));
		else
			std::cout << line << std::endl;
	}
}

void Printer::printPopulation(Simulator & simulator)
{
	setForegroundColor(COLOR::yellow);

	for (auto&chromosome : simulator.getPopulation())
	{
		for (auto&gene : chromosome.first)
		{
			std::cout << (int)gene;
		}
		std::cout << std::endl;
	}
}

void Printer::clear()
{
	system("cls");
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

void Printer::matchColor(std::string colorString)
{
	if (colorString == constants::color::RED) setForegroundColor(COLOR::red);
	else if(colorString==constants::color::GREEN) setForegroundColor(COLOR::red);
	else if (colorString == constants::color::BLUE) setForegroundColor(COLOR::blue);
	else if (colorString == constants::color::YELLOW) setForegroundColor(COLOR::yellow);
}
