/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:45:59 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/15 11:45:59 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <string>
# include <cstdlib>
# include <map>
# include <iomanip>

# define LIGHT_BLUE "\033[1;34m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define WHITE_ITALIC "\033[1;3;37m"
# define NO_COLOR "\033[0m"

class BitcoinExchange
{
	public:
		typedef std::map<std::string, float>			map;
		typedef std::map<std::string, float>::iterator	it;

	public:
		BitcoinExchange(const std::string &fileName);
		~BitcoinExchange();

		void calculate();

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void	getData();
		void	readInputLines();
		bool parsing(std::string &str);
		it		findRate(std::string &date);

	private:
		std::ifstream	_file;
		std::ifstream	_data;
		map				_dataMap;
		std::string		_buffer;
		std::string		_date;
		std::string		_value;
		std::size_t		_index;
//		std::size_t		_savedPos;
};

#endif //BITCOINEXCHANGE_HPP
