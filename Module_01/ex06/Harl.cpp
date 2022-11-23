/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:57:57 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/22 17:57:57 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return;
}

Harl::~Harl()
{
	return;
}

void	Harl::complain(std::string level)
{
	void (Harl::*arrayptr[])() = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	std::string arraystr[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (level == arraystr[i])
		{
			switch (i)
			{
				case 0:
					(this->*arrayptr[++i - 1])();
				case 1:
					(this->*arrayptr[++i - 1])();
				case 2:
					(this->*arrayptr[++i - 1])();
				case 3:
					(this->*arrayptr[++i - 1])();
			}
		}
	}

	return;
}

void	Harl::_debug()
{
	std::cout << "This is a DEBUG message" << std::endl;
	return;
}

void	Harl::_info()
{
	std::cout << "This is an INFO message" << std::endl;
	return;
}

void	Harl::_warning()
{
	std::cout << "This is a WARNING message" << std::endl;
	return;
}

void	Harl::_error()
{
	std::cout << "This is an ERROR message" << std::endl;
	return;
}
