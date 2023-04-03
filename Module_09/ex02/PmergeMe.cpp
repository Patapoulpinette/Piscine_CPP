/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:42:02 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/29 14:42:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool parsing(std::vector<std::string> &args)
{
	if (args.empty())
		return false;
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
	{
		if (it->empty())
		{
			std::cout << RED << "Error:" << NO_COLOR << " only digits allowed" << std::endl;
			return false;
		}
		for (std::string::iterator ite = it->begin(); ite != it->end(); ite++)
		{
			if (!isdigit(*ite))
			{
				std::cout << RED << "Error:" << NO_COLOR << " only digits allowed" << std::endl;
				return false;
			}
		}
		double tmp = std::strtod(it->c_str(), NULL);
		if (tmp < 0 || tmp > std::numeric_limits<int>::max())
		{
			std::cout << RED << "Error:" << NO_COLOR << " must be a positive integer" << std::endl;
			return false;
		}
	}
	//Checking duplicates
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
	{
		for (std::vector<std::string>::iterator ite = it + 1; ite != args.end(); ite++)
		{
			if (std::strtod(it->c_str(), NULL) == std::strtod(ite->c_str(), NULL))
			{
				std::cout << RED << "Error:" << NO_COLOR << " no duplicates allowed" << std::endl;
				return false;
			}
		}
	}
	return true;
}
