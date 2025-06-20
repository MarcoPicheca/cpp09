#ifndef BITCOIN_HPP
#define BITCOIN_HPP
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <exception>
#include <string>

class Bitcoin
{
	private:
		std::vector<double> _valuesCsv;
		std::vector<unsigned int> _yearCsv;
		std::vector<unsigned int> _monthCsv;
		std::vector<unsigned int> _dayCsv;
		std::vector<std::string> _dateCsv;
		std::vector<double> _valuesInput;
		std::vector<std::string> _dateInput;
		double result;
	public:
		Bitcoin();
		Bitcoin(const Bitcoin& copy);
		Bitcoin& operator=(const Bitcoin& copy);
		void	csvParser();
		int		inputParser(std::string& arg);
		void	inputError(const char * str, int flag, int index);
		int		findClosestDate(unsigned int y, unsigned int m, unsigned int d);
		~Bitcoin();
};

#endif