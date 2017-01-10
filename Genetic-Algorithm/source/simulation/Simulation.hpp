#pragma once

#include <vector>


class Simulation
{
	static void createPopulation(int8_t chromosomesAmmount, int8_t genesAmmount);

public:

	static void starAlgorithm(int8_t chromosomesAmmount, int8_t genesAmmount);

private:
	static std::vector<bool*> population;
	static void 
};