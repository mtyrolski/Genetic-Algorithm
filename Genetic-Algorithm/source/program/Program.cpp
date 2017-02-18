#include "Program.hpp"

Program::Program(Printer & _printer)
	:state(MENU),printer(_printer)
{
}

void Program::stop()
{
	state = OFF;
}

bool Program::running()
{
	return state != OFF;
}

void Program::takeAction(unsigned char && mark)
{
	switch(state)
	{ 
		case MENU:
		{
			switch (mark)
			{
			case '1': printer.clear(); printer.print("source/data/data_loading.txt"); break;
			case '2': this->stop(); return;
			}	
		}
	}
}

void Program::setState(STATE _state)
{
	state = _state;
}

Program::STATE Program::getState()
{
	return state;
}
