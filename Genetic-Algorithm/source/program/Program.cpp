#include "Program.hpp"

Program::Program()
{
	state = ON;
}

void Program::stop()
{
	state = OFF;
}

bool Program::running()
{
	return state == ON;
}
