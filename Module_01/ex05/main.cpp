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

int	main()
{
	Harl	instance;
	Harl*	instance_p = &instance;

	//pointer to a member function of class Harl
	void	(Harl::*f)(std::string);
	//pointer take the adresse of a function of class Harl
	f = &Harl::complain;

	//we can also write it on 1 line only, like this:
	//void	(Harl::*f)(std::string) = &Harl::complain;

	//call functions
	std::cout << "Direct use of instance with operator \".*\"" << std::endl;
	(instance.*f)("DEBUG");
	(instance.*f)("INFO");
	(instance.*f)("WARNING");
	(instance.*f)("ERROR");
	std::cout << '\n' << "Use of pointer to instance with operator \"->*\"" << std::endl;
	(instance_p->*f)("DEBUG");
	(instance_p->*f)("INFO");
	(instance_p->*f)("WARNING");
	(instance_p->*f)("ERROR");

	return (0);
}
