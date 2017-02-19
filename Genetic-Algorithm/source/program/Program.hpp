#pragma once

#include "printer/Printer.hpp"
#include "simulator/Simulator.hpp"

class Program final
{
public:
	static enum STATE
	{
		OFF,
		MENU,
		STARTING_SIMULATION,
		DATA_LOADING,
		SIMULATION,
		HISTORY_VIEW
	};

	Program(Printer&, Simulator&);

	void stop();

	bool running();

	void takeAction(unsigned char&&);

	void setState(STATE);

	void loadData();

	STATE getState();

private:
	Printer& printer;
	Simulator& simulator;
	STATE state;

	//Number for scroll history
	int number;
};
