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
	: _file(fileName, std::ios::in), _csv("data.csv", std::ios::in)
{
	if (!_file.is_open())
	{
		std::cerr << "Error: failed to open " << fileName << std::endl;
		return;
	}
	getLines();
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
	_csv.close();
	//TODO maybe delete some data ?
}

void BitcoinExchange::getLines()
{
	//get lines (one by one) of input file
	while (getline(_file, _buffer))
	{
		std::cout << "BUFFER: " << _buffer << std::endl;
		_index = _buffer.find('|', 0);
		std::cout << "index: " << _index << std::endl;
		_line.append(_buffer, 0, _index - 1);
		std::cout << "LINE: " << _line << std::endl;
		_value.append(_buffer, _index + 1, std::string::npos);
		std::cout << "VALUE: " << _value << std::endl;
		//TODO parsing line
		//TODO parsing value
//		std::cout << "STOF: " << std::stof(_value) << std::endl;
//		_map.insert(std::pair<std::string, float>(_line, std::stof(_value)));
		std::cout << "THERE" << std::endl;
		_line.clear();
		_value.clear();
	}
	//TOREMOVE (test)
	for (std::map<std::string, float>::iterator itMap = _map.begin(); itMap != _map.end(); itMap++)
		std::cout << itMap->first << "| " << itMap->second << std::endl;
}
