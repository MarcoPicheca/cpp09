#include "Bitcoin.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	Bitcoin ciao;
	try
	{
		ciao.csvParser();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	std::string arg;
	arg.append(av[1]);
	if (arg.empty())
		return (std::cerr << "Error: empty input\n", 1);
	ciao.inputParser(arg);
	return 0;
}
