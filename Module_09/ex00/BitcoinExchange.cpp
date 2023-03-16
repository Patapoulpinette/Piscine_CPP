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
	: _file(fileName, std::ios::in), _data("data.csv", std::ios::in)
{
	if (!_file.is_open())
	{
		std::cerr << "Error: failed to open " << fileName << std::endl;
		return;
	}
	if (!_data.is_open())
	{
		std::cerr << "Error: failed to open data.csv " << std::endl;
		return;
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
	getInputLines();
	//getDataLines();
}

void BitcoinExchange::getInputLines()
{
	//get lines (one by one) of input file
	while (getline(_file, _buffer))
	{
		std::cout << LIGHT_BLUE << "BUFFER: " << _buffer << NO_COLOR << std::endl;
		_index = _buffer.find('|');
		std::cout << "index:  " << _index << std::endl;
		if (_index == 11)
		{
			_line.append(_buffer, 0, _index - 1);
			std::cout << "LINE:   " << _line << std::endl;
			_value.append(_buffer, _index + 2, std::string::npos);
			std::cout << "VALUE:  " << _value << std::endl;
		}
		else
		{
			_line.append("Error: bad input => " + _buffer);
			std::cout << "LINE:   " << _line << std::endl;
			_value.append("-1");
			std::cout << "VALUE:  " << _value << std::endl;
		}
		//TODO parsing line
		//TODO parsing value
		std::cout << "STOF: " << std::stof(_value) << std::endl;
		_inputMap.insert(std::pair<std::string, float>(_line, std::stof(_value)));
		std::cout << GREEN << "INPUTMAP: " << _line << " | " << _inputMap[_line] << NO_COLOR << std::endl;
		_line.clear();
		_value.clear();
	}
	//TOREMOVE (test)
	std::cout << "----- DISPLAY OF MAP -----\n";
	for (std::map<std::string, float>::iterator itMap = _inputMap.begin(); itMap != _inputMap.end(); itMap++)
	{
		if (itMap->first.find("Error") == std::string::npos)
			std::cout << itMap->first << "| " << itMap->second << std::endl;
		else
			std::cout << itMap->first << std::endl;
	}
}

void BitcoinExchange::getDataLines()
{
	//get lines (one by one) of data file
	while (getline(_data, _buffer))
	{
		std::cout << "BUFFER: " << _buffer << std::endl;
		_index = _buffer.find(',', 0);
		std::cout << "index: " << _index << std::endl;
		_line.append(_buffer, 0, _index - 1);
		std::cout << "LINE: " << _line << std::endl;
		_value.append(_buffer, _index + 1, std::string::npos);
		std::cout << "VALUE: " << _value << std::endl;
		//TODO parsing line
		//TODO parsing value
//		std::cout << "STOF: " << std::stof(_value) << std::endl;
//		_inputMap.insert(std::pair<std::string, float>(_line, std::stof(_value)));
		std::cout << "THERE" << std::endl;
		_line.clear();
		_value.clear();
	}
	//TOREMOVE (test)
	for (std::map<std::string, float>::iterator itMap = _dataMap.begin(); itMap != _dataMap.end(); itMap++)
		std::cout << itMap->first << "| " << itMap->second << std::endl;
}
