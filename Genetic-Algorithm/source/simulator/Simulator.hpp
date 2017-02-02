#pragma once

#include <vector>
#include <stdlib.h>     
#include <time.h>     
#include <algorithm>

class Simulator
{
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

	void mutatePopulation();

	void confirmNewPopulation();

public:

	Simulator(int8_t chromosomesAmmount, int8_t genesAmmount, float p_c, float p_m);

	void simulate();

	void createNewPopulation(int8_t chromosomesAmmount, int8_t genesAmmount);

private:

	float crossoverProbability;

	float mutationProbability;

	//Population { chromosomes/Adaptation)
	std::vector<std::pair<std::vector<bool>,float>> population;

	//Population { chromosomes/Adaptation)
	std::vector<std::vector<bool>> tempPopulation; //to remove
};