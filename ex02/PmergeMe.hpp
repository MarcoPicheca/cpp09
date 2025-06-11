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
		std::deque<T> jacobSthal;
		std::deque<T> max_list;
		std::deque<T> min_list;
		bool n_is_odd;
	public:
		PmergeMe();
		~PmergeMe();
		bool allDifferent();
		int checkArg(const std::string& input);
		int createMaxMinList();

		/**
		 * PRINT / DEBUG
		 * 
		 * 
		 */
		void printDeque(std::deque<T> &list);
		std::deque<T> getMaxList() const;
		std::deque<T> getMinList() const;
		// const std::deque<T> insertMinList() const;
};

bool is_not_all_digits(const std::string& str);

template <typename T>
void jacobInsert(const T& element, std::deque<T>& dest)
{
	size_t mid = dest.begin() + (dest.end() - dest.begin()) / 2;
	T tmp;
	typename std::deque<T>::iterator it = dest.at(mid);
	if (element > *it)
	{
		while (it != dest.end())
		{
			if (element < *it)
			{
				dest.insert(it, element);
				return ;
			}
			it++;
		}
		dest.insert(std::next(it), element);
	}
}

template <typename T>
void instertMinlist(std::deque<T> min_list, std::deque<T> max_list, std::deque<T> jacob_list)
{
	typename std::deque<T>::iterator it = jacob_list.begin();
	while (it != jacob_list.end())
	{
		jacobInsert(min_list.at(*it), max_list);
		it++;
	}
	
}

template <typename T>
std::deque<T> generateJacobsthal(int n)
{
	std::deque<T> J(n + 1, 0);
	if (n >= 1)
		J[1] = 1;
	for (int i = 2; i <= n; ++i)
		J[i] = J[i - 1] + 2 * J[i - 2];
	return J;
}

template <typename T>
std::deque<T> PmergeMe<T>::getMaxList() const
{
	return this->max_list;
}

template <typename T>
std::deque<T> PmergeMe<T>::getMinList() const
{
	return this->min_list;
}

template <typename T>
void PmergeMe<T>::printDeque(std::deque<T> &list)
{
	typename std::deque<T>::iterator it;

	// std::cout << "MAX: " << std::endl;
	// for (it = max_list.begin(); it != max_list.end(); it++)
	// {
	// 	std::cout << "	" << *it << std::endl;
	// }
	// std::cout << "min: " << std::endl;
	// for (it = min_list.begin(); it != min_list.end(); it++)
	// {
	// 	std::cout << "	" << *it << std::endl;
	// }
	// std::cout << "tokens: " << std::endl;
	// for (it = tokens.begin(); it != tokens.end(); it++)
	// {
	// 	std::cout << "	" << *it << std::endl;
	// }
	std::cout << "sort max list: " << std::endl;
	for (it = list.begin(); it != list.end(); it++)
	{
		std::cout << "	" << *it << std::endl;
	}
}

template <typename T>
int PmergeMe<T>::createMaxMinList()
{
	typename std::deque<T>::iterator it;
	typename std::deque<T>::iterator it_2;

	it = tokens.begin();
	while (it != tokens.end())
	{
		it_2 = it + 1;
		if (it_2 == tokens.end())
			break ;
		max_list.push_back(std::max(*it, *it_2));
		min_list.push_back(std::min(*it, *it_2));
		it = it + 2;
	}
	if (it != tokens.end())
	{
		n_is_odd = true;
		min_list.push_back(*it);
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



template<typename T>
bool PmergeMe<T>::allDifferent()
{
	std::set<T> seen;
	typename std::deque<T>::iterator it;
	
	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (seen.find(*it) != seen.end())
		return false;
		seen.insert(*it);
	}
	return true;
}

template <typename T>
int PmergeMe<T>::checkArg(const std::string& input)
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


template <typename T>
void merge(std::deque<T> &list, int left, int median, int right)
{
	int n1 = median - left + 1;
	int n2 = right - median;
	int i = -1;
	int j = -1;
	int k = left;
	std::deque<T> tmp_L(n1), tmp_R(n2);

	while (++i < n1)
		tmp_L[i] = list[left + i];
	while (++j < n2)
		tmp_R[j] = list[median + 1 + j];
	j = 0;
	i = 0;
	while (i < n1 && j < n2)
	{
		if (tmp_L[i] <= tmp_R[j])
			list[k] = tmp_L[i++];
		else
			list[k] = tmp_R[j++];
		k++;
	}
	while (i < n1)
		list[k++] = tmp_L[i++];
	while (j < n2)
		list[k++] = tmp_R[j++];		
}

template <typename T>
void mergeSort(std::deque<T> &list, int left, int right)
{
	if (left >= right)
		return ;
	int median = left + (right - left) / 2;
	mergeSort(list, left, median);
	mergeSort(list, median + 1, right);
	merge(list, left, median, right);
}

#endif