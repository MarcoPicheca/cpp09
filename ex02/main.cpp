#include "PmergeMe.hpp"

bool is_not_all_digits(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return true;
	}
	return false;
}

int check_arg(const std::string input, std::deque<unsigned int> &tokens)
{
	std::istringstream iss(input);
	std::string tmp;
	while (iss >> tmp)
	{
		if (is_not_all_digits(tmp))
			return (std::cerr << "Errore: token non valido: " << tmp << "\n", 1);
		else
		{
			int value = std::atoi(tmp.c_str());
			tokens.push_back(value);
		}
	}
	return 0;
}

int main (int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong input" << std::endl;
		return 1;
	}
	std::deque<unsigned int> tokens;
	const std::string input(av[1]);
	if (check_arg(input, tokens))
		return 1;
	std::cout << "Before sorting: ";
	std::deque<unsigned int>::iterator it;
	for (it = tokens.begin(); it + 1 != tokens.end(); it++)
		std::cout << *it << " ";
	std::cout << *it;
	std::cout << std::endl;
	return 0;
}