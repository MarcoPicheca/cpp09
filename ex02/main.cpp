#include "PmergeMe.hpp"

int main (int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong input" << std::endl;
		return 1;
	}
	const std::string input(av[1]);
	PmergeMe<unsigned int> pm;
	if (pm.checkArg(input))
		return (std::cerr << "Error: wrong input" << std::endl, 1);
	pm.createMaxMinList();
	// std::cout << "Before sorting: ";
	// std::deque<unsigned int>::iterator it;
	// // for (it = tokens.begin(); it + 1 != tokens.end(); it++)
	// // 	std::cout << *it << " ";
	// // std::cout << *it;
	// // std::cout << std::endl;
	return 0;
}