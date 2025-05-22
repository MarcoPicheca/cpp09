#ifndef BITCOIN_HPP
#define BITCOIN_HPP
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>

class Bitcoin
{
	private:
		std::vector<double> _valuesCsv;
		std::vector<unsigned int> _yearCsv;
		std::vector<unsigned int> _monthCsv;
		std::vector<unsigned int> _dayCsv;
		std::vector<std::string> _dateCsv;
		std::vector<double> _valuesInput;
		std::vector<unsigned int> _yearInput;
		std::vector<unsigned int> _monthInput;
		std::vector<unsigned int> _dayInput;
		std::vector<std::string> _dateInput;
	public:
		Bitcoin();
		// Bitcoin(const Bitcoin& copy);
		// Bitcoin& operator=(const Bitcoin& copy);
		void csvParser();
		int inputParser(std::string& arg);
		void inputError(const char * str, int flag);
		~Bitcoin();
};

void	Bitcoin::csvParser()
{
	std::ifstream file("./data.csv");
	std::string line;
	// size_t	i = 0;
	
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string value_str;
		std::string date;
		if (std::getline(ss, date, ',') && std::getline(ss, value_str, ','))
		{
			_valuesCsv.push_back(std::atof(value_str.c_str()));
			std::stringstream ss2(date);
			_dateCsv.push_back(date);
			std::string year;
			std::string month;
			std::string day;
			std::getline(ss2, year, '-');
			std::getline(ss2, month, '-');
			std::getline(ss2, day, '-');
			_yearCsv.push_back(std::atoi(year.c_str()));
			_monthCsv.push_back(std::atoi(month.c_str()));
			_dayCsv.push_back(std::atoi(day.c_str()));
			// std::cout << _yearCsv[i] << ' ' << _monthCsv[i] << ' ' << _dayCsv[i] << std::endl;
		}
		// i++;
	}
}

void Bitcoin::inputError(const char * str, int flag)
{
	std::cout << str;
	if (flag == 0)
		std::cout << std::endl;
	_yearInput.push_back(-1);
	_monthInput.push_back(-1);
	_dayInput.push_back(-1);
	_valuesInput.push_back(-1);
}

int Bitcoin::inputParser(std::string& arg)
{
	std::ifstream file(arg.c_str());
	std::string line;
	int i = -1;
	std::string year;
	std::string month;
	std::string day;
	std::string value_str;
	std::string date;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		++i;
		std::stringstream ss(line);
		if (std::getline(ss, date, '|') && std::getline(ss, value_str, '|'))
		{
			double val = std::atof(value_str.c_str());
			if (val < 0)
			{
				inputError("Error: not a positive number.", 0);
				continue;
			}
			else if (val > 100)
			{
				inputError("Error: too large number.", 0);
				continue;
			}
			_valuesInput.push_back(val);
			std::stringstream ss2(date);
			_dateInput.push_back(date);
			std::getline(ss2, year, '-');
			std::getline(ss2, month, '-');
			std::getline(ss2, day, ' ');
			if (year.find_first_not_of("0123456789") != std::string::npos
				|| month.find_first_not_of("0123456789") != std::string::npos
				|| day.find_first_not_of("0123456789") != std::string::npos)
			{
				inputError("Error: non numerical input.", 0);
				continue;
			}
			int y = std::atoi(year.c_str());
			int m = std::atoi(month.c_str());
			int d = std::atoi(day.c_str());
			if (y > 2022 || y < 2009 || m < 1 || m > 12 || d < 1 || d > 31
				|| (m == 2 && d > 29) || (y != 2012 && y != 2016 && y != 2020 && d == 29))
			{
				inputError("Error: bad input => ", 1);
				std::cout << y << '-' << m << '-' << d;
				continue ;
			}
			_yearInput.push_back(y);
			_monthInput.push_back(m);
			_dayInput.push_back(d);
			std::cout << _yearInput[i] << ' ' << _monthInput[i] << ' ' << _dayInput[i] << ' '  << _valuesInput[i] << " valore di i = " << i << std::endl;
		}
		else
			inputError("Error: could't find a value.", 0);
	}
	return 0;
}

Bitcoin::Bitcoin()
{
}

Bitcoin::~Bitcoin()
{
}

#endif