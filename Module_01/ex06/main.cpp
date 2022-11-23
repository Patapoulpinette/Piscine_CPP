/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:05 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/22 17:56:05 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string message = argv[1];
		if (message == "DEBUG" || message == "INFO" || message == "WARNING" || message == "ERROR")
		{
			Harl instance;

			//pointer to a member function of class Harl
			void    (Harl::*f)(std::string);
			//pointer take the adresse of a function of class Harl
			f = &Harl::complain;

			//we can also write it on 1 line only, like this:
			//void	(Harl::*f)(std::string) = &Harl::complain;

			//call function
			(instance.*f)(message);
		}
		else
			std::cout << "Probably talking about insignificant problem" << std::endl;
	}
	else
		std::cerr << "Wrong number of arguments: ./HarlFilter [DEBUG/INFO/WARNING/ERROR]" << std::endl;

	return (0);
}
