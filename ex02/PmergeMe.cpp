#include "PmergeMe.hpp"

int mergin_insert_sort(const std::string& input)
{
	PmergeMe<long long> pm;
	if (pm.checkArg(input))
		return 1;
	pm.createMaxMinList();
	if (containsNonPositive(pm.getTokens()))
		return 1;
	std::deque<long long> max_list = pm.getMaxList();
	std::deque<long long> min_list = pm.getMinList();
	std::deque<long long> jacobSthal = generateJacobsthal<long long>(min_list.size());
	mergeSort(max_list, 0, max_list.size() - 1);
	std::deque<long long> sortedList = instertMinlist<long long>(min_list, max_list, jacobSthal);
	pm.printDeque(sortedList);	
}

bool is_all_spaces(const std::string& input)
{
	std::string::const_iterator it = input.begin();
	while (it != input.end())
	{
		if (!std::isspace(*it))
			return 0;
		it++;
	}
	return 1;	
}

bool is_not_all_digits(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return true;
	}
	return false;
}

