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

	static void chooseChromosomes();

	static void crossPopulation();

	static void crossPair(std::pair<std::vector<bool>&, std::vector<bool>&> chromosomes);

public:

	static void starAlgorithm(int8_t chromosomesAmmount, int8_t genesAmmount,float pk,float pm);

private:

	static float pk;

	static float pm;

	//Population { chromosomes/Adaptation)
	static std::vector<std::pair<std::vector<bool>,float>> population;

	//Population { chromosomes/Adaptation)
	static std::vector<std::vector<bool>> tempPopulation;
};