#pragma once

#include "printer/Printer.hpp"

class Program final
{
public:
	static enum STATE
	{
		OFF,
		MENU,
		DATA_LOADING,
		HISTORY_VIEW
	};

	Program(Printer &printer);

	void stop();

	bool running();

	void takeAction(unsigned char&& mark);

	void setState(STATE _state);

	STATE getState();

private:
	Printer& printer;
	STATE state;
};
