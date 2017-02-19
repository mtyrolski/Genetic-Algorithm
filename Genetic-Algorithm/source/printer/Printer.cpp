#include "Printer.hpp"


Printer::Printer()
{
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Printer::print(std::string&& path)
{
	std::ifstream ifile(path, std::ifstream::in);

	std::string line;

	while (std::getline(ifile, line))
	{
		if (line[0] == '#')
			matchColor(line.substr(1,line.size()-1));
		else
			std::cout << line << std::endl;
	}
}

void Printer::printPopulation(Simulator & simulator, int number)
{
	for (auto&chromosome : simulator.getHistory(number))
	{
		for (auto&gene : chromosome)
		{
			if (gene)
				setForegroundColor(COLOR::green);
			else
				setForegroundColor(COLOR::red);

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

void Printer::printDescription(int& number, int&& historySize)
{
	this->print("source/data/simulation.txt");

	if (number > historySize - 1) number = 0;
	else if (number < 0) number = historySize - 1;

	this->setForegroundColor(Printer::COLOR::red);
	std::cout << "Cycle: ";
	this->setForegroundColor(Printer::COLOR::green);
	std::cout << number;
	this->setForegroundColor(Printer::COLOR::red);
	std::cout << " / ";
	this->setForegroundColor(Printer::COLOR::green);
	std::cout << historySize - 1 << std::endl;
	this->setForegroundColor(Printer::COLOR::yellow);
}

void Printer::matchColor(std::string colorString)
{
	if (colorString == constants::color::RED) setForegroundColor(COLOR::red);
	else if(colorString==constants::color::GREEN) setForegroundColor(COLOR::green);
	else if (colorString == constants::color::BLUE) setForegroundColor(COLOR::blue);
	else if (colorString == constants::color::YELLOW) setForegroundColor(COLOR::yellow);
}
