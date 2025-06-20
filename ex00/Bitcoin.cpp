#include "Bitcoin.hpp"

Bitcoin::Bitcoin(const Bitcoin& copy)
{
	_valuesCsv = copy._valuesCsv;
	_yearCsv = copy._yearCsv;
	_monthCsv = copy._monthCsv;
	_dayCsv = copy._dayCsv;
	_dateCsv = copy._dateCsv;
	_valuesInput = copy._valuesInput;
	_dateInput = copy._dateInput;
	result = copy.result;
}

Bitcoin& Bitcoin::operator=(const Bitcoin& copy)
{
	if (this != &copy)
	{
		_valuesCsv = copy._valuesCsv;
		_yearCsv = copy._yearCsv;
		_monthCsv = copy._monthCsv;
		_dayCsv = copy._dayCsv;
		_dateCsv = copy._dateCsv;
		_valuesInput = copy._valuesInput;
		_dateInput = copy._dateInput;
		result = copy.result;
	}
	return *this;
}

void	Bitcoin::csvParser()
{
	std::ifstream file("./data.csv");
	std::string line;
	std::string value;
	std::string date;
	std::string year;
	std::string month;
	std::string day;
	
	if (!std::getline(file, line))
		throw(std::runtime_error("Something is wrong!"));
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		if (std::getline(ss, date, ',') && std::getline(ss, value, ','))
		{
			_valuesCsv.push_back(std::atof(value.c_str()));
			std::stringstream ss2(date);
			_dateCsv.push_back(date);
			std::getline(ss2, year, '-');
			std::getline(ss2, month, '-');
			std::getline(ss2, day, '-');
			_yearCsv.push_back(std::atoi(year.c_str()));
			_monthCsv.push_back(std::atoi(month.c_str()));
			_dayCsv.push_back(std::atoi(day.c_str()));
		}
	}
	if (_yearCsv.empty() || _monthCsv.empty() || _dayCsv.empty())
		throw(std::runtime_error("Something is wrong in data.csv!"));
}

void Bitcoin::inputError(const char * str, int flag, int index)
{
	std::cout << str;
	if (flag == 0)
		std::cout << std::endl;
	_valuesInput[index] = -1;
}

int Bitcoin::findClosestDate(unsigned int y, unsigned int m, unsigned int d)
{
	int index = 0;
	while (_yearCsv[index] != y)
		index++;
	while (_monthCsv[index] != m)
		index++;
	unsigned int range_1 = index;
	unsigned int range_2 = 0;
	while (_monthCsv[index] == m)
		index++;
	range_2 = index;
	while (_dayCsv[range_1] != d && _dayCsv[range_1] <= d && range_1 < range_2)
		range_1++;
	if (d == _dayCsv[range_1])
		return range_1;
	if (d + 1 == _dayCsv[range_1])
		return range_1;
	else
		return range_1 - 1;
	return 0;
}

int Bitcoin::inputParser(std::string& arg)
{
	std::ifstream file(arg.c_str());
	if (file.peek() == std::ifstream::traits_type::eof())
		return (std::cerr << "Error: empty input\n", 1);
	std::string line;
	std::string value;
	std::string date;
	std::string year;
	std::string month;
	std::string day;
	unsigned int y = 0;
	unsigned int m = 0;
	unsigned int d = 0;
	int i = -1;
	int ind = -1;

	if (!std::getline(file, line))
		return (inputError("Error: insert some input file", 0, 0), 1);
	while (std::getline(file, line))
	{
		++i;
		std::stringstream ss(line);
		if (std::getline(ss, date, '|') && std::getline(ss, value, '|'))
		{
			double val = std::atof(value.c_str());
			if (val < 0)
			{
				inputError("Error: not a positive number.", 0, i);
				continue;
			}
			else if (val > 1000)
			{
				inputError("Error: too large number.", 0, i);
				continue;
			}
			_valuesInput.push_back(val);
			_dateInput.push_back(date);
			std::stringstream ss2(date);
			std::getline(ss2, year, '-');
			std::getline(ss2, month, '-');
			std::getline(ss2, day, ' ');
			if (year.find_first_not_of("0123456789") != std::string::npos
				|| month.find_first_not_of("0123456789") != std::string::npos
				|| day.find_first_not_of("0123456789") != std::string::npos)
			{
				inputError("Error: non numerical input.", 0, i);
				continue;
			}
			y = std::atoi(year.c_str());
			m = std::atoi(month.c_str());
			d = std::atoi(day.c_str());
			if (y > 2022 || y < 2009 || m < 1 || m > 12 || d < 1 || d > 31
				|| (m == 2 && d > 29) || (y != 2012 && y != 2016 && y != 2020 && d == 29))
			{
				inputError("Error: bad input => ", 1, i);
				std::cout << date << std::endl;
				continue ;
			}
			ind = findClosestDate(y, m, d);
			result = _valuesInput[i] * _valuesCsv[ind];
			std::cout << _dateCsv[ind] << " => " << _valuesInput[i] << " = " <<  result << std::endl;
		}
		else
        {
			if (!date.empty())
			{
				inputError("Error: bad input => ", 1, i);
				std::cout << date << std::endl;
			}
			else
				inputError("Error: bad input.", 0, i);
        }
	}
	return 0;
}

Bitcoin::Bitcoin()
{
}

Bitcoin::~Bitcoin()
{
}
