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

	Simulator(int chromosomesAmmount = 8, int genesAmmount = 8, float p_c = 0.75f, float p_m = 0.02f);

	void simulate(int generations);

	void createNewPopulation(int chromosomesAmmount=8, int genesAmmoun=8);

	std::vector<std::pair<std::vector<bool>, float>> getPopulation();

	std::vector<std::vector<bool>> getHistory(int number);

	int getHistorySize();

	void setPropeties(int chromosomesAmmount = 8, int genesAmmount = 8, float p_c = 0.75f, float p_m = 0.02f);



private:

	float crossoverProbability;

	float mutationProbability;

	//Population { chromosomes/Adaptation)
	std::vector<std::pair<std::vector<bool>, float>> population;

	//Population{chromosomes{genes}}
	std::vector<std::vector<std::vector<bool>>> history;
};