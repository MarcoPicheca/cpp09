#ifndef BITCOIN_HPP
#define BITCOIN_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>

class Bitcoin
{
	private:
		std::vector<float> _values;
		std::vector<unsigned int> _year;
		std::vector<unsigned int> _month;
		std::vector<unsigned int> _day;
		std::vector<std::string> _date;
	public:
		Bitcoin();
		Bitcoin(const Bitcoin& copy);
		Bitcoin& operator=(const Bitcoin& copy);
		void csvParser();
		~Bitcoin();
};

void	Bitcoin::csvParser()
{
	std::ifstream file("data.csv");
	std::string line;
	size_t	i = 0;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string value_str;
		if (std::getline(ss, _date[i], ',') && std::getline(ss, value_str, ','))
		{
			double val = std::atof(value_str.c_str());
			_values[i] = static_cast<float>(val);
			std::stringstream ss2(_date[i]);
			std::string year;
			std::string month;
			std::string day;
			std::getline(ss2, year, '-');
			std::getline(ss2, month, '-');
			std::getline(ss2, day, '-');
			_year[i] = std::atoi(year.c_str());
			_month[i] = std::atoi(month.c_str());
			_day[i] = std::atoi(day.c_str());
		}
		i++;
	}
}

Bitcoin::Bitcoin()
{
}

Bitcoin::~Bitcoin()
{
}

#endif