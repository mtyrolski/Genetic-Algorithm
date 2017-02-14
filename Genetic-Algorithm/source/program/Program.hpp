#pragma once

class Program final
{
public:
	static enum STATE
	{
		ON,
		OFF
	};

	Program();

	void stop();

	bool running();

private:
	STATE state;
};
