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

# define RED "\033[0;31m"
# define WHITE_ITALIC "\033[1;3;37m"
# define NO_COLOR "\033[0m"

class BitcoinExchange
{
	public:
		typedef std::map<std::string, float>			map;
		typedef std::map<std::string, float>::iterator	it;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void calculate(const std::string &fileName);

	private:
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void	getData();
		bool	parsing(std::string &str);
		it		findRate(std::string &date);

	private:
		map				_dataMap;
		std::string		_buffer;
		std::string		_date;
		std::string		_value;
		std::size_t		_index;
};

#endif //BITCOINEXCHANGE_HPP
