#pragma once

#include <vector>
#include <stdlib.h>     
#include <time.h>     

class Simulation
{
	static void createPopulation(int8_t chromosomesAmmount, int8_t genesAmmount);
	static void randomGenes();
public:

	static void starAlgorithm(int8_t chromosomesAmmount, int8_t genesAmmount);

private:
	static std::vector<std::vector<bool>> population;
	static void 
};