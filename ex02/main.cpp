#include "PmergeMe.hpp"

int main (int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong input" << std::endl;
		return 1;
	}
	const std::string input(av[1]);
	if (input.empty() || is_all_spaces(input))
	{
		std::cerr << "Error: wrong input" << std::endl;
		return 1;
	}
	// if ft_merge
	if (mergin_insert_sort(input))
		return (std::cerr << "Error: wrong input" << std::endl, 1);
	return 0;
}