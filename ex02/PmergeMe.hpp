#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <cmath>
#include <set>
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
		bool n_is_odd;
	public:
		PmergeMe();
		~PmergeMe();
		int checkArg(const std::string& input) const;
		int createMaxMinList() const;
		bool allDifferent() const;
		int mergeMaxList() const;
		int assignJacobSthal() const;
		const std::deque<T> insertMinList() const;
};

template <typename T>
int PmergeMe<T>::createMaxMinList() const
{
	size_t size = tokens.size();
	typename std::deque<T>::const_iterator it;
	typename std::deque<T>::const_iterator it_2;

	it = tokens.begin();
	while (it != tokens.end())
	{
		++it_2;
		if (it_2 == tokens.end())
			break ;
		max_list.push_back(std::max(*it, *it_2));
		min_list.push_back(std::min(*it, *it_2));
		it = it + 2;
	}
	if (it != tokens.end())
	{
		n_is_odd = true;
		min_list.push_back(it);
	}
	else
		n_is_odd = false;
	return 0;
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


template<typename T>
bool PmergeMe<T>::allDifferent() const
{
	std::set<T> seen;
	typename std::deque<T>::const_iterator it;

	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (seen.find(*it) != seen.end())
			return false;
		seen.insert(*it);
	}
	return true;
}

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
	if (!allDifferent())
		return (std::cerr << "Errore: Doppi numeri\n", 1);
	return 0;
}

#endif