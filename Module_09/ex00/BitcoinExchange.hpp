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

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &fileName);
		~BitcoinExchange();

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void getLines();

		std::ifstream					_file;
		std::ifstream					_csv;
		std::map<std::string, float>	_map;
		std::string						_buffer;
		std::string						_line;
		std::string						_value;
		std::size_t						_index;
//		std::size_t						_savedPos;
};

#endif //BITCOINEXCHANGE_HPP
