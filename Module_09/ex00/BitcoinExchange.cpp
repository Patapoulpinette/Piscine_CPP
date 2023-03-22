/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:46:10 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/15 11:46:10 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &fileName)
	: _file(fileName.c_str(), std::ios::in), _data("data.csv", std::ios::in)
{
	if (!_file.is_open())
	{
		std::cerr << RED << "Error:" << NO_COLOR << " failed to open " << WHITE_ITALIC << fileName << std::endl;
		exit(-1);
	}
	if (!_data.is_open())
	{
		std::cerr << RED << "Error:" << NO_COLOR << " failed to open " << WHITE_ITALIC << "data.csv " << std::endl;
		exit(-1);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	(void) rhs;
	//TODO at the end
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	_file.close();
	_data.close();
	//TODO maybe delete some data ?
}

void BitcoinExchange::calculate()
{
	getData();
	readInputLines();
}

void BitcoinExchange::getData()
{
	//get lines (one by one) of data file
	while (getline(_data, _buffer))
	{
		_index = _buffer.find(',', 0);
		if (_index == std::string::npos)
		{
			std::cerr << RED << "Error:" << NO_COLOR << " invalid data file" << std::endl;
			exit(-1);
		}
		_date.append(_buffer, 0, _index);
		_value.append(_buffer, _index + 1, std::string::npos);
		_dataMap.insert(std::pair<std::string, float>(_date, std::atof(_value.c_str())));
		_date.clear();
		_value.clear();
	}
	//TOREMOVE (test) ----------------------------------------------------------------------------------
	std::cout << "----- DISPLAY OF DATA MAP -----\n";
	for (std::map<std::string, float>::iterator itMap = _dataMap.begin(); itMap != _dataMap.end(); itMap++)
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << itMap->first << " | " << itMap->second << std::endl;
	}
	std::cout << "----- END OF DATA MAP -----\n";
	//ENDOFREMOVE --------------------------------------------------------------------------------------
}

void BitcoinExchange::readInputLines()
{
	//get lines (one by one) of input file
	while (getline(_file, _buffer))
	{
		parsing(_buffer);
		//std::map<std::string, float>::iterator rate = findRate(_date);
		it itRate = _dataMap.lower_bound(_date);
		if (itRate == _dataMap.end())
		{
			std::cout << RED << "Error:" << NO_COLOR << " no match for this date => " << _date;
			_date.clear();
			_value.clear();
			continue;
		}
		std::cout << GREEN << _date << " => " << _value << " = " << std::strtod(_value.c_str(), NULL) * itRate->second << NO_COLOR << std::endl;
		_date.clear();
		_value.clear();
	}
}

void BitcoinExchange::parsing(std::string &str)
{
	std::cout << LIGHT_BLUE << "BUFFER: " << str << NO_COLOR << std::endl;
	_index = str.find('|');
	if (_index == 11)
	{
		_date.append(str, 0, _index - 1);
		_value.append(str, _index + 2, std::string::npos);
	}
	else
	{
		_date.append("Error: bad input => " + str);
	}
	//TODO parsing line
	//TODO parsing value
}
//
//BitcoinExchange::it BitcoinExchange::findRate(std::string &date)
//{
//	it itRate = _dataMap.find(date);
//	if (itRate == _dataMap.end())
//		itRate = _dataMap.lower_bound(date);
//	return itRate;
//}
