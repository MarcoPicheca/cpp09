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

