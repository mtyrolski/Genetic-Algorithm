#include "Simulator.hpp"


void Simulator::createNewPopulation(int8_t chromosomesAmmount, int8_t genesAmmount)
{
	population.clear();

	while (chromosomesAmmount--)
	{
		population.emplace_back();
		for (uint16_t i = 0; i < genesAmmount; i++) population[population.size() - 1].first.emplace_back(rand() % 100 >= 50);
	}
}

std::vector<std::pair<std::vector<bool>, float>>& Simulator::getPopulation(int number)
{
	return history[number];
}

int Simulator::getHistorySize()
{
	return history.size();
}

void Simulator::randomGenes()
{
	for (auto& chromosomes : population)
		for (auto& genes : chromosomes.first)
			genes = rand() % 100 >= 50;
}

void Simulator::setAdaption()
{
	firstStageAdaptation();
	secondStageAdaptation(countAdaptation());
	thirdStageAdaptation();
}

void Simulator::firstStageAdaptation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation)
{
	for (size_t i = 0; i < population.size(); i++)
		tempPopulation[i].second = std::count(population[i].first.begin(), population[i].first.end(), true);
}

void Simulator::firstStageAdaptation()
{
	for (auto& var : population)
		var.second = std::count(var.first.begin(), var.first.end(), true);
}

int Simulator::countAdaptation()
{
	auto sum = 0;

	for (auto& var : population)
		sum += var.second;

	return sum;
}

void Simulator::secondStageAdaptation(int sumAdaptation)
{
	for (auto& var : population)
		var.second /= (float)sumAdaptation;
}

void Simulator::thirdStageAdaptation()
{
	for (size_t i = 1; i < population.size(); i++)
		population[i].second += population[i-1].second;
}

void Simulator::chooseChromosomes(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation)
{
	std::vector<int> randomNumbers;

	for (size_t i = 0; i < population.size(); i++)
		randomNumbers.emplace_back(rand()%100);

	for (auto&number : randomNumbers)
	{
		for (size_t i = 0; i < population.size(); i++)
		{
			if (number < population[i].second * 100)
			{
				tempPopulation.emplace_back(population[i]);
				break;
			}
		}
			
	}
}

void Simulator::crossPopulation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation)
{
	for (size_t i = 0; i < tempPopulation.size(); i+=2)
		crossPair(std::pair<std::vector<bool>&, std::vector<bool>&>(tempPopulation[i].first, tempPopulation[i + 1].first));
	
}

void Simulator::crossPair(std::pair<std::vector<bool>&, std::vector<bool>&> chromosomes)
{
	auto crossoverProb = (rand() % 100)/100.f;

	if (crossoverProb < crossoverProbability)
		return;

	auto firstCopy = chromosomes.first;

	int lk = rand()%chromosomes.first.size();

	for (int8_t i = lk; i < chromosomes.first.size(); i++)
		chromosomes.first[i] = chromosomes.second[i];

	for (int8_t i = lk; i < chromosomes.first.size(); i++)
		chromosomes.second[i] = firstCopy[i];
	
}

void Simulator::mutatePopulation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation)
{
	float p_m;

	for (auto & chromosome : tempPopulation)
	{
		for (auto & gene : chromosome.first)
		{
			p_m = (rand() % 100) / 100.f;
			
			if (p_m < mutationProbability)
				gene = !gene;
		}
	}

}

void Simulator::confirmNewPopulation(std::vector<std::pair<std::vector<bool>, float>>& tempPopulation)
{
	for (size_t i = 0; i < population.size(); i++)
		population[i].first = tempPopulation[i].first;
	
	setAdaption();
}

Simulator::Simulator(int8_t chromosomesAmmount, int8_t genesAmmount, float p_c, float p_m)
{
	setPropeties(chromosomesAmmount, genesAmmount, p_c, p_m);
}

void Simulator::setPropeties(int8_t chromosomesAmmount, int8_t genesAmmount, float p_c, float p_m)
{
	mutationProbability = p_m;
	crossoverProbability = p_c;

	createNewPopulation(chromosomesAmmount, genesAmmount);
}

void Simulator::simulate(int generations)
{
	srand(time(NULL));


	for (size_t i = 0; i < generations; i++)
	{
		//Population { chromosomes/Adaptation)
		std::vector<std::pair<std::vector<bool>,float>> tempPopulation;

		setAdaption();
		chooseChromosomes(tempPopulation);
		crossPopulation(tempPopulation);
		mutatePopulation(tempPopulation);
		confirmNewPopulation(tempPopulation);

		firstStageAdaptation(tempPopulation);

		history.push_back(tempPopulation);
	}
}
