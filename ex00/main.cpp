#include "Bitcoin.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	Bitcoin ciao;
	ciao.csvParser();
	std::string arg;
	arg.append(av[1]);
	ciao.inputParser(arg);
	
	return 0;
}
