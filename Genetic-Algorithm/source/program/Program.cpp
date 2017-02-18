#include "Program.hpp"

Program::Program(Printer& _printer)
:state(MENU),printer(_printer)
{
}


void Program::stop()
{
	state = OFF;
}

bool Program::running()
{
	return state != OFF;
}

void Program::takeAction(unsigned char && mark)
{
	switch(state)
	{ 
		case MENU:
		{
			switch (mark)
			{
			case '1': state = STARTING_SIMULATION;  printer.clear(); printer.print("source/data/starting_simulation.txt"); return;
			case '2': this->stop(); return;
			}	
		}

		case STARTING_SIMULATION:
		{
			switch (mark)
			{
			case '1': state = DATA_LOADING; printer.clear(); printer.print("source/data/data_loading.txt"); this->loadData(); return;
			case '2': state = MENU; printer.clear();  printer.print("source/data/menu.txt"); return;
			}
		}
	}
}

void Program::setState(STATE _state)
{
	state = _state;
}

void Program::loadData()
{

	int8_t ammountOfChromosomes, ammountOfGenes;
	float crossoverPropability, mutationPropability;
	int cycles;

	printer.setForegroundColor(Printer::COLOR::green);

	std::cout << std::endl << "Enter ammount of chromosomes... ";
	std::cin >> ammountOfChromosomes;

	std::cout << std::endl << "Enter ammount of genes in each chromosom... ";
	std::cin >> ammountOfGenes;

	std::cout << std::endl << "Enter ammount of crossover propability... ";
	std::cin >> crossoverPropability;

	std::cout << std::endl << "Enter ammount of mutation propability... ";
	std::cin >> mutationPropability;

	std::cout << std::endl << "Enter ammount of cycles... ";
	std::cin >> cycles;

	if (ammountOfChromosomes <= 0 || ammountOfGenes <= 0 ||
		crossoverPropability < 0 || crossoverPropability>1 ||
		mutationPropability < 0 || mutationPropability>1||
		cycles<=0)
	{
		std::cout << "You have entered wrong data... try again...";
		Sleep(1500);
		printer.clear();
		state = STARTING_SIMULATION;
		printer.print("source/data/starting_simulation.txt");
		return;
	}
	else
	{
		printer.clear();
		Simulator simulator(ammountOfChromosomes, ammountOfGenes, crossoverPropability, mutationPropability);
		simulator.simulate(cycles);
	}

}

Program::STATE Program::getState()
{
	return state;
}
