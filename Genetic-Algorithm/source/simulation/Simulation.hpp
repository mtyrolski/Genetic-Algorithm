#pragma once

#include <vector>
#include <stdlib.h>     
#include <time.h>     
#include <algorithm>

class Simulation
{
	static void createPopulation(int8_t chromosomesAmmount, int8_t genesAmmount);
	static void randomGenes();
	static void setAdaption();

	static int countAdaptation();

	//Counting
	static void firstStageAdaptation();

	//Count -> percent
	static void secondStageAdaptation(int sumAdaptation);

	//Sum
	static void thirdStageAdaptation();

public:

	static void starAlgorithm(int8_t chromosomesAmmount, int8_t genesAmmount);

private:

	//Population { chromosomes/Adaptation)
	static std::vector<std::pair<std::vector<bool>,float>> population;
};