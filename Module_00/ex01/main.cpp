/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:18 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/14 13:13:18 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

int	main()
{
	std::string command;
	Phonebook	phonebook;
	int 		index = 0;

	while (command != "EXIT")
	{
		if (command == "ADD")
		{
			if (phonebook.add_function(index))
				return (1);
			index++;
		}
		if (command == "SEARCH")
			if (phonebook.search_function())
				return (1);
		std::cout << "Please, enter a command [ADD, SEARCH or EXIT] : ";
		if (!getline(std::cin, command))
			return (1);
		if (index > 7)
			index = 0;
	}
	return (0);
}
