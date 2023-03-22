/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:46:03 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/15 11:46:03 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange btc;
		btc.calculate(argv[1]);
	}
	else
		std::cerr << "Error: wrong number of arguments: ./btc [file]" << std::endl;
	return (0);
}
