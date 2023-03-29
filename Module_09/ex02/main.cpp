/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:43:01 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/29 14:43:01 by dbouron          ###   ########.fr       */
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
	return true;
}

std::vector<unsigned int> convert(std::vector<std::string> &strVector)
{
	std::vector<unsigned int> uIntVector;
	for (std::vector<std::string>::iterator it = strVector.begin(); it != strVector.end(); it++)
		uIntVector.push_back(static_cast<int>(std::strtod(it->c_str(), NULL)));
	return uIntVector;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::vector<std::string> strVector(argv + 1, argv + argc);
		if (!parsing(strVector))
			return 1;
		std::vector<unsigned int>				uIntVector = convert(strVector);
		PmergeMe<std::vector<unsigned int> >	vector(uIntVector);
//		PmergeMe<std::deque<unsigned int> >		deque(uIntDeque);
		vector.sort();
//		deque.sort();
	}
	return 0;
}
