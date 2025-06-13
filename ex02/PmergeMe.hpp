#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <cmath>
#include <set>
#include <ctime>
#include <algorithm>
#include <deque>
#include <list>
#include <sstream>
#include <string>
#include <cstdlib>

template <typename T>
class PmergeMe
{
	private:
		std::deque<T> tokens;
		std::deque<T> jacobSthal;
		std::deque<T> max_deque;
		std::deque<T> min_deque;
		std::list<T> tokens_list;
		std::list<T> jacobSthal;
		std::list<T> max_list;
		std::list<T> min_list;
	public:
		PmergeMe();
		~PmergeMe();

		// CHECKERS
		bool allDifferent();
		int checkArg(const std::string& input);
		int createMaxMinDeque();
		int createMaxMinList();
		// PRINTER
		void printDeque(std::deque<T> &deque);

		// GETTER
		std::deque<T> getMaxDeque() const;
		std::deque<T> getMinDeque() const;
		std::deque<T> getTokens() const;

		std::list<T> getTokensList() const;
		std::list<T> getMaxList() const;
		std::list<T> getMinList() const;

};		

// FUNZIONE
bool is_not_all_digits(const std::string& str);
bool is_all_spaces(const std::string& input);
int mergin_insert_sort(const std::string& input);

#endif