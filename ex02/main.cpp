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
	std::deque<unsigned int> max_list = pm.getMaxList();
	std::deque<unsigned int> min_list = pm.getMinList();
	std::deque<unsigned int> jacobSthal = generateJacobsthal<unsigned int>(min_list.size());
	pm.printDeque(max_list);
	mergeSort(max_list, 0, max_list.size() - 1);
	pm.printDeque(max_list);
	// std::cout << "Before sorting: ";
	// std::deque<unsigned int>::iterator it;
	// // for (it = tokens.begin(); it + 1 != tokens.end(); it++)
	// // 	std::cout << *it << " ";
	// // std::cout << *it;
	// // std::cout << std::endl;
	return 0;
}