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
	enum class COLOR
	{
		red,
		green,
		blue,
		yellow
	};

	Printer();
	void print(std::string&& path);
	void printPopulation(Simulator& simulator, int number);
	void clear();
	void setForegroundColor(COLOR color);
	void printDescription(int& number, int&& historySize);

private:

	void matchColor(std::string colorString);

	HANDLE hout;
};