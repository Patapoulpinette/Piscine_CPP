/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:31:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/15 13:31:59 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

// CONSTRUCTOR -----------------------------------------------------------------

Phonebook::Phonebook()
{
	std::cout << "Phonebook constructor called" << std::endl;
	return;
}

// DESTRUCTOR ------------------------------------------------------------------

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destructor called" << std::endl;
	return;
}

int	Phonebook::add_function(int index)
{
	std::string answer;

	std::cout << "Enter your first name: ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_first_name(answer);
	std::cout << "Enter your last name: ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_last_name(answer);
	std::cout << "Enter your nickname: ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_nickname(answer);
	std::cout << "Enter your phone number: ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_phone_number(answer);
	std::cout << "Enter your darkest secret: ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_darkest_secret(answer);
	return (0);
}

//TODO limit strings to 10 char and if string > 10 set the last char to .
int	Phonebook::search_function(void)
{
	int 		index = 0;
	std::string	input;

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	while (index < 8)
	{
		if (this->_directory[index].get_first_name() != "")
		{
			std::cout << "│" << std::setw(10) << index + 1 << "│" << std::setw(10)
					  << this->_directory[index].get_first_name() << "│" << std::setw(10)
					  << this->_directory[index].get_last_name() << "│" << std::setw(10)
					  << this->_directory[index].get_nickname() << "│" << std::endl;
		}
		index++;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

	index = -1;
	while (index < 0 || index > 8)
	{
		std::cout << "Enter contact index to display: ";
		if (!getline(std::cin, input))
			return (1);
		if (input.size() == 1 && std::isdigit(input[0]))
		{
			index = stoi(input);
			if (index < 0 || index > 8)
				std::cout << "contact " << index << " doesn't exist. Enter a contact index between 1 to 8." << std::endl;
		}
		else
			std::cout << "Please, enter only 1 digit" << std::endl;
	}
	//TODO if contact empty ne paas afficher
	std::cout << "Contact " << index << std::endl;
	std::cout << "First name: " << this->_directory[index -1].get_first_name() << std::endl;
	std::cout << "Last name: " << this->_directory[index -1].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_directory[index -1].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->_directory[index -1].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->_directory[index -1].get_darkest_secret() << std::endl;

	return (0);
}
