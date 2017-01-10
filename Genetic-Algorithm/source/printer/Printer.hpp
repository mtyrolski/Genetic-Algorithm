#pragma once

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>

class Printer
{
public:
	Printer();
	void printMenu();
	
private:

	enum class COLOR
	{
		red,
		green,
		blue,
		yellow
	};

	enum class INTENSITY
	{
		YES,
		NO
	};

	void setForegroundColor(COLOR color);


	HANDLE hout;
};