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
		std::cout << _buffer << std::endl;
		_pos = _buffer.find('|', _savedPos);
		_line.append(_buffer, 0, _pos - 1);
		_value.append(_buffer, _pos, _buffer.size() - _pos);
		_map.insert(std::pair<std::string, float>(_line, std::stof(_value)));//TODO
		_line.clear();
		_value.clear();
	}
}
