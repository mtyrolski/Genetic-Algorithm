#pragma once

#include <vector>
#include <stdlib.h>     
#include <time.h>     
#include <algorithm>

class Simulator
{
	void createPopulation(int8_t chromosomesAmmount, int8_t genesAmmount);
	void randomGenes();
	void setAdaption();

	int countAdaptation();

	//Counting
	void firstStageAdaptation();

	//Count -> percent
	void secondStageAdaptation(int sumAdaptation);

	//Sum
	void thirdStageAdaptation();

	void chooseChromosomes();

	void crossPopulation();

	void crossPair(std::pair<std::vector<bool>&, std::vector<bool>&> chromosomes);

public:

	void starAlgorithm(int8_t chromosomesAmmount, int8_t genesAmmount,float pk,float pm);

private:

	float pk;

	float pm;

	//Population { chromosomes/Adaptation)
	std::vector<std::pair<std::vector<bool>,float>> population;

	//Population { chromosomes/Adaptation)
	std::vector<std::vector<bool>> tempPopulation;
};