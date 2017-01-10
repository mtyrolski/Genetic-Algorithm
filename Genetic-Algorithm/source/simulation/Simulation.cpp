#include "Simulation.hpp"

std::vector<bool*> Simulation::population;

void Simulation::createPopulation(int8_t chromosomesAmmount, int8_t genesAmmount)
{
	while (chromosomesAmmount--)
	{
		population.emplace_back();
		population[population.size() - 1] = new bool[genesAmmount];
	}
}

void Simulation::starAlgorithm(int8_t chromosomesAmmount, int8_t genesAmmount)
{
	createPopulation(chromosomesAmmount,genesAmmount);
}
