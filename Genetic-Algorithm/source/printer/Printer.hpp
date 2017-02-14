#pragma once

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "config/Config.hpp"
#include "simulator/Simulator.hpp"

class Printer
{
public:
	Printer();
	void printMenu();
	void printPopulation(Simulator& simulator);
	void clear();

private:

	enum class COLOR
	{
		red,
		green,
		blue,
		yellow
	};

	void setForegroundColor(COLOR color);
	void matchColor(std::string colorString);

	HANDLE hout;
};