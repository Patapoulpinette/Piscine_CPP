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
# include <map>

# define LIGHT_BLUE "\033[1;34m"
# define GREEN "\033[0;32m"
# define NO_COLOR "\033[0m"

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &fileName);
		~BitcoinExchange();

		void calculate();

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void getInputLines();
		void getDataLines();

		std::ifstream					_file;
		std::ifstream					_data;
		std::map<std::string, float>	_inputMap;
		std::map<std::string, float>	_dataMap;
		std::string						_buffer;
		std::string						_line;
		std::string						_value;
		std::size_t						_index;
//		std::size_t						_savedPos;
};

#endif //BITCOINEXCHANGE_HPP
