#include "printer/Printer.hpp"
#include "simulator/Simulator.hpp"

int main()
{
	Printer printer;
	Simulator simulator;

	int n;
	cout << "Give ammount of generations to do..." << endl;
	cin >> n;
	cout << endl;

	simulator.simulate(n);
	printer.printPopulation(simulator);

	return 0;
}