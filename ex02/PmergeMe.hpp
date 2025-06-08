#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <cmath>
#include <ctime>
#include <deque>
#include <sstream>
#include <string>
#include <cstdlib>

template <typename T>
class PmergeMe
{
	private:
		std::deque<T> tokens;
		std::deque<T> max_list;
		std::deque<T> min_list;
	public:
		PmergeMe();
		~PmergeMe();
		int checkArg(const std::string& input) const;
		int createMaxMinList() const;
		int mergeMaxList() const;
		int assignJacobSthal() const;
		const std::deque<T> insertMinList() const;
};

template <typename T>
int PmergeMe<T>::createMaxMinList() const
{
	size_t size = tokens.size();
	std::deque<T>::iterator it;
	for (it = tokens.begin(); it + 2 != tokens.end(); it++)
		;
}

template <typename T>
PmergeMe<T>::PmergeMe()
{
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

bool is_not_all_digits(const std::string& str);

template <typename T>
int PmergeMe<T>::checkArg(const std::string& input) const
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
#endif