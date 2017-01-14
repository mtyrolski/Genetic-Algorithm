#include "Simulation.hpp"

std::vector<std::pair<std::vector<bool>, float>> Simulation::population;

void Simulation::createPopulation(int8_t chromosomesAmmount, int8_t genesAmmount)
{
	while (chromosomesAmmount--)
	{
		population.emplace_back();
		for (uint16_t i = 0; i < genesAmmount; i++) population[population.size() - 1].first.push_back(rand() % 100 >= 50);
	}
}

void Simulation::randomGenes()
{
	srand(time(NULL));

	for (auto& chromosomes : Simulation::population)
		for (auto& genes : chromosomes.first)
			genes = rand() % 100 >= 50;
}

void Simulation::starAlgorithm(int8_t chromosomesAmmount, int8_t genesAmmount)
{
	createPopulation(chromosomesAmmount,genesAmmount);


}
