#include "PmergeMe.hpp"

int main (int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong input" << std::endl;
		return 1;
	}
	const std::string input(av[1]);
	PmergeMe<long long> pm;
	if (pm.checkArg(input))
		return (std::cerr << "Error: wrong input" << std::endl, 1);
	pm.createMaxMinList();
	if (containsNonPositive(pm.getTokens()))
		return 1;
	std::deque<long long> max_list = pm.getMaxList();
	std::deque<long long> min_list = pm.getMinList();
	std::deque<long long> jacobSthal = generateJacobsthal<long long>(min_list.size());
	mergeSort(max_list, 0, max_list.size() - 1);
	std::deque<long long> sortedList = instertMinlist<long long>(min_list, max_list, jacobSthal);
	pm.printDeque(sortedList);
	return 0;
}