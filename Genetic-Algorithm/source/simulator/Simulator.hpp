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

	//Counting for statistics
	void firstStageAdaptation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation);

	//Counting for simulation
	void firstStageAdaptation();


	//Count -> percent
	void secondStageAdaptation(int sumAdaptation);


	//Sum
	void thirdStageAdaptation();

	void chooseChromosomes(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation);

	void crossPopulation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation);

	void crossPair(std::pair<std::vector<bool>&, std::vector<bool>&> chromosomes);

	void mutatePopulation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation);

	void confirmNewPopulation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation);

public:

	Simulator(int8_t chromosomesAmmount= 8, int8_t genesAmmount = 8, float p_c = 0.75f, float p_m=0.02f);

	void setPropeties(int8_t chromosomesAmmount = 8, int8_t genesAmmount = 8, float p_c = 0.75f, float p_m = 0.02f);


	void simulate(int generations);

	void createNewPopulation(int8_t chromosomesAmmount, int8_t genesAmmount);

	// population{chromosomes/Adaptation}/number
	std::vector<std::pair<std::vector<bool>, float>>& getPopulation(int number);

	int getHistorySize();
	
private:

	float crossoverProbability;

	float mutationProbability;

	//Population {chromosomes/Adaptation}
	std::vector<std::pair<std::vector<bool>,float>> population;

	std::vector<std::vector<std::pair<std::vector<bool>, float>>> history;
};