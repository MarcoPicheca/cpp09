#include "PmergeMe.hpp"

/**
 * 
 * SORTING LIST
 * 
 */

// TODO insertMinList, insertionSortList e printList nella sezione PRINT

template <typename T>
void mergeList(std::list<T>& list, int left, int median, int right)
{
	typename std::list<T>::iterator it_start = list.begin();
	typename std::list<T>::iterator it_mid = list.begin();
	typename std::list<T>::iterator it_end = list.begin();
	std::list<T> tmp_Left;
	std::list<T> tmp_Right;
	typename std::list<T>::iterator it;
	int i;

	for (i = 0; i < left; ++i)
		++it_start;
	for (i = 0; i < median + 1; ++i)
		++it_mid;
	for (i = 0; i < right + 1; ++i)
		++it_end;
	for (it = it_start; it != it_mid; ++it)
		tmp_Left.push_back(*it);
	for (it = it_mid; it != it_end; ++it)
		tmp_Right.push_back(*it);
	
	typename std::list<T>::iterator it_left = tmp_Left.begin();
	typename std::list<T>::iterator it_right = tmp_Right.begin();
	typename std::list<T>::iterator it_merge = it_start;

	while (it_left != tmp_Left.end() && it_right != tmp_Right.end())
	{
		if (*it_left <= *it_right)
		{
			*it_merge = *it_left;
			++it_left;
		}
		else
		{
			*it_merge = *it_right;
			++it_right;
		}
		++it_merge;
	}
	while (it_left != tmp_Left.end())
	{
		*it_merge = *it_left;
		++it_left;
		++it_merge;
	}
	while (it_right != tmp_Right.end())
	{
		*it_merge = *it_right;
		++it_right;
		++it_merge;
	}
}

template <typename T>
void mergeSortList(std::list<T> &list, int left, int right)
{
	if (left >= right)
		return ;
	int median = left + (right - left) / 2;
	mergeSortList(list, left, median);
	mergeSortList(list, median + 1, right);
	mergeList(list, left, median, right);
}

template <typename T>
std::list<T> generateJacobsthalList(int n)
{
	std::list<T> J;
	if (n >= 1)
		J.push_back(0);
	if (n >= 2)
		J.push_back(1);

	typename std::list<T>::iterator it1 = J.begin();
	typename std::list<T>::iterator it2 = it1;
	++it2;

	for (int i = 2; i < n; ++i)
	{
		int val = *it2 + 2 * (*it1);
		J.push_back(val);
		++it1;
		++it2;
	}
	return J;
}

template <typename T>
void	insertionSortList(T& min_item, std::list<T>& max)
{
	int median = 0 + ((max.size() - 1) - 0) / 2;
	typename std::list<T>::iterator it_mid = max.begin();
	typename std::list<T>::iterator it;
	int i;
	for (i = 0; i < median + 1; i++)
		it_mid++;
	if (min_item < *it_mid)
	{
		it = it_mid;
		it--;
		i--;
		while (min_item < *it && i > 0 && it != max.begin())
		{
			it--;
			i--;
		}
		if (min_item > *it)
			max.insert(++it, min_item);
		else
			max.push_front(min_item);
	}
	else if (min_item > *it_mid)
	{
		it = it_mid;
		it++;
		while (it != max.end() && min_item > *it)
			it++;
		if (it == max.end())
			max.push_back(min_item);
		else
			max.insert(it, min_item);
	}
}

template <typename T>
std::list<T> instertMinList(std::list<T> min, std::list<T>& max, std::set<T>& jacob) {
    T i = 0;
    typename std::set<T>::iterator it_jacob = jacob.begin();
    typename std::list<T>::iterator it_min = min.begin();

    while (it_jacob != jacob.end()) {
        while (i != *it_jacob) {
            i++;
            it_min++;
        }
        if (*it_min != -1)
            insertionSortList(*it_min, max);
        *it_min = -1;
        it_jacob++;
    }

    for (it_min = min.begin(); it_min != min.end(); ++it_min) {
        if (*it_min != -1 && std::find(max.begin(), max.end(), *it_min) == max.end())
            insertionSortList(*it_min, max);
    }

    return max;
}


template <typename T>
void sortingList(PmergeMe<T>& pm)
{
	std::list<T> max_list = pm.getMaxList();
	std::list<T> min_list = pm.getMinList();
	std::list<T> jacobSthalList = generateJacobsthalList<T>(min_list.size());
	std::set<T> jacobListUnici(jacobSthalList.begin(), jacobSthalList.end());
	mergeSortList(max_list, 0, max_list.size() - 1);
	std::list<T> sortedList = instertMinList<T>(min_list, max_list, jacobListUnici);
	pm.printList(sortedList);
}

/**
 * 
 * SORTING DEQUE
 * 
 */

template <typename T>
void insertionSort(T& element, std::deque<T>& dest)
{
	typename std::deque<T>::iterator it = dest.begin() + (dest.end() - dest.begin()) / 2;
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
		dest.insert(it, element);
	}	
	else if(element < *it)
	{
		while (it != dest.begin())
		{
			if (element > *it)
			{
				dest.insert(it + 1, element);
				return ;
			}	
			it--;
		}	
		if (element > *it)
		{
			dest.insert(it + 1, element);
			return ;
		}	
		else
			dest.insert(it, element);
	}	
}

template <typename T>
std::deque<T> instertMinDeque(std::deque<T>& min_deque, std::deque<T>& max_deque, std::deque<T>& jacob_deque)
{
	typename std::deque<T>::iterator it = jacob_deque.begin();
	int i = 0;
	while (it != jacob_deque.end() && *it < static_cast<T>(min_deque.size()))
	{
		if (i++ == 2)
		{
			it++;
			continue;
		}	
		insertionSort(min_deque[*it], max_deque);
		it++;
	}	
	i = 0;
	for (it = min_deque.begin(); it != min_deque.end(); it++)
	{
		if (std::find(max_deque.begin(), max_deque.end(), *it) == max_deque.end())
			insertionSort(min_deque[i], max_deque);
		i++;	
	}	
	std::deque<T> sorted(max_deque);
	return sorted;
}

template <typename T>
void merge(std::deque<T> &deque, int left, int median, int right)
{
	int n1 = median - left + 1;
	int n2 = right - median;
	int i = -1;
	int j = -1;
	int k = left;
	std::deque<T> tmp_L(n1), tmp_R(n2);

	while (++i < n1)
		tmp_L[i] = deque[left + i];
	while (++j < n2)
		tmp_R[j] = deque[median + 1 + j];
	j = 0;
	i = 0;
	while (i < n1 && j < n2)
	{
		if (tmp_L[i] <= tmp_R[j])
			deque[k] = tmp_L[i++];
		else
			deque[k] = tmp_R[j++];
		k++;
	}
	while (i < n1)
		deque[k++] = tmp_L[i++];
	while (j < n2)
		deque[k++] = tmp_R[j++];		
}

template <typename T>
void mergeSortDeque(std::deque<T> &deque, int left, int right)
{
	if (left >= right)
		return ;
	int median = left + (right - left) / 2;
	mergeSortDeque(deque, left, median);
	mergeSortDeque(deque, median + 1, right);
	merge(deque, left, median, right);
}

template <typename T>
std::deque<T> generateJacobsthalDeque(int n)
{
	std::deque<T> J(n, 0);

	if (n >= 1)
		J[1] = 1;
	for (int i = 2; i < n; ++i)
		J[i] = J[i - 1] + 2 * J[i - 2];
	return J;
}

template <typename T>
void sortingDeque(PmergeMe<T>& pm)
{
	std::deque<T> max_deque = pm.getMaxDeque();
	std::deque<T> min_deque = pm.getMinDeque();
	std::deque<T> jacobSthal = generateJacobsthalDeque<T>(min_deque.size());
	mergeSortDeque(max_deque, 0, max_deque.size() - 1);
	std::deque<T> sortedDeque = instertMinDeque<T>(min_deque, max_deque, jacobSthal);
	pm.printDeque(sortedDeque);
}

// PRINT DEQUE
template <typename T>
void PmergeMe<T>::printDeque(std::deque<T> &deque)
{
	typename std::deque<T>::iterator it;

	std::cout << "STD::DEQUE" << std::endl;
	std::cout << "tokens unsorted:";
	for (it = tokens.begin(); it != tokens.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	if (deque.empty()) return ;
	std::cout << "sorted deque:";
	for (it = deque.begin(); it != deque.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

// PRINT LIST
template <typename T>
void PmergeMe<T>::printList(std::list<T> &list)
{
	typename std::list<T>::iterator it;

	std::cout << "\nSTD::LIST" << std::endl;
	std::cout << "tokens unsorted:";
	for (it = tokens_list.begin(); it != tokens_list.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	if (list.empty()) return ;
	std::cout << "sorted list:";
	for (it = list.begin(); it != list.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

// CREATING TOKENS
template <typename T>
int PmergeMe<T>::createMaxMinDeque()
{
	typename std::deque<T>::iterator it;
	typename std::deque<T>::iterator it_2;

	it = tokens.begin();
	while (it != tokens.end())
	{
		it_2 = it + 1;
		if (it_2 == tokens.end())
			break ;
		max_deque.push_back(std::max(*it, *it_2));
		min_deque.push_back(std::min(*it, *it_2));
		it = it + 2;
	}
	if (it != tokens.end())
		min_deque.push_back(*it);
	return 0;
}

template <typename T>
int PmergeMe<T>::createMaxMinList()
{
	typename std::list<T>::iterator it;
	typename std::list<T>::iterator it_2;

	it = tokens_list.begin();
	while (it != tokens_list.end())
	{
		it_2 = it;
		it_2++;
		if (it_2 == tokens_list.end())
			break ;
		max_list.push_back(std::max(*it, *it_2));
		min_list.push_back(std::min(*it, *it_2));
		it++;
		it++;
	}
	if (it != tokens_list.end())
		min_list.push_back(*it);
	return 0;
}

// DEFAULT CONSTRUCTOR
template <typename T>
PmergeMe<T>::PmergeMe()
{
}

// DEFAULT DESTRUCTOR
template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

// GETTERS DEQUE
template <typename T>
std::deque<T> PmergeMe<T>::getMaxDeque() const
{
	return this->max_deque;
}

template <typename T>
std::deque<T> PmergeMe<T>::getMinDeque() const
{
	return this->min_deque;
}

template <typename T>
std::deque<T> PmergeMe<T>::getTokens() const
{
	return this->tokens;
}

// GETTERS LIST
template <typename T>
std::list<T> PmergeMe<T>::getMaxList() const
{
	return this->max_list;
}

template <typename T>
std::list<T> PmergeMe<T>::getMinList() const
{
	return this->min_list;
}

template <typename T>
std::list<T> PmergeMe<T>::getTokensList() const
{
	return this->tokens_list;
}

// CHECK ON TOKENS
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
bool containsNonPositive(const std::deque<T>& tokens, const std::list<T>& tokens_list)
{
	typename std::deque<T>::const_iterator it;
	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (*it <= 0)
			return (std::cerr << "Errore: numeri non positivi\n", true);
	}
	typename std::list<T>::const_iterator it_list;
	for (it_list = tokens_list.begin(); it_list != tokens_list.end(); ++it_list)
	{
		if (*it_list <= 0)
			return (std::cerr << "Errore: numeri non positivi\n", true);
	}
	return false;
}

template <typename T>
bool containsNonPositiveList(const std::list<T>& tokens)
{
	typename std::list<T>::const_iterator it;
	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (*it <= 0)
			return (std::cerr << "Errore: numeri non positivi\n", true);
	}
	return false;
}

// CHECKS ON INPUT 
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

template <typename T>
int PmergeMe<T>::checkArg(const std::string& input)
{
	std::istringstream iss(input);
	std::string tmp;
	
	while (iss >> tmp)
	{
		if (is_not_all_digits(tmp)) return (std::cerr << "Errore: token non valido: " << tmp << "\n", 1);
		else
		{
			int value = std::atoi(tmp.c_str());
			tokens.push_back(value);
			tokens_list.push_back(value);
		}
	}
	if (!allDifferent()) return (std::cerr << "Errore: Doppi numeri\n", 1);
	return 0;
}

// GET TIME
double getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1e6 + tv.tv_usec;
}

// MAIN FUNCTION
int mergin_insert_sort(const std::string& input)
{
	PmergeMe<long long> pm;
	if (pm.checkArg(input))
		return 1;

	pm.createMaxMinDeque();
	pm.createMaxMinList();

	if (containsNonPositive(pm.getTokens(), pm.getTokensList()))
		return 1;
	// sorting deque
	double startDeque = getTime();
	sortingDeque(pm);
	double endDeque = getTime();
	double timeDeque = endDeque - startDeque;
	// sorting list
	double startList = getTime();
	sortingList(pm);
	double endList = getTime();
	double timeList = endList - startList;
	std::cout << std::fixed << std::setprecision(3);

	std::cout << "Time to process a range of " << pm.getTokens().size()
	          << " elements with std::deque : " << timeDeque << " us" << std::endl;

	std::cout << "Time to process a range of " << pm.getTokensList().size()
	          << " elements with std::list  : " << timeList << " us" << std::endl;

	return 0;
}
