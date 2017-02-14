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

	void chooseChromosomes(std::vector<std::vector<bool>>& tempPopulation);

	void crossPopulation(std::vector<std::vector<bool>>& tempPopulation);

	void crossPair(std::pair<std::vector<bool>&, std::vector<bool>&> chromosomes);

	void mutatePopulation(std::vector<std::vector<bool>>& tempPopulation);

	void confirmNewPopulation(std::vector<std::vector<bool>>& tempPopulation);

public:

	Simulator(int8_t chromosomesAmmount= 8, int8_t genesAmmount = 8, float p_c = 0.75f, float p_m=0.02f);

	void simulate(int generations);

	void createNewPopulation(int8_t chromosomesAmmount, int8_t genesAmmount);

	std::vector<std::pair<std::vector<bool>, float>> getPopulation();

private:

	float crossoverProbability;

	float mutationProbability;

	//Population { chromosomes/Adaptation)
	std::vector<std::pair<std::vector<bool>,float>> population;
};