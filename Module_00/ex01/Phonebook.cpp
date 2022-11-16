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

/*// SET FUNCTIONS ---------------------------------------------------------------

void	Phonebook::set_directory(std::string field, Contact value, int index)
{
	(void) field, (void) value, (void) index;
*//*	if (field == "FNAME")
		this->_directory[index].get_first_name() = value;
	if (field == "LNAME")
		this->_directory[index].get_last_name() = value;
	if (field == "NNAME")
		this->_directory[index].get_nickname() = value;
	if (field == "PNUMBER")
		this->_directory[index].get_phone_number() = value;
	if (field == "DSECRET")
		this->_directory[index].get_darkest_secret() = value;*//*
	return;
}

// GET FUNCTIONS ---------------------------------------------------------------

Contact	Phonebook::get_directory(int index) const
{
	return this->_directory[index];
}*/

// OTHER FUNCTIONS -------------------------------------------------------------

int	Phonebook::add_function(int index)
{
	std::string answer;

	std::cout << "Enter your first name : ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_first_name(answer);
	std::cout << "Enter your last name :";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_last_name(answer);
	std::cout << "Enter your nickname : ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_nickname(answer);
	std::cout << "Enter your phone number : ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_phone_number(answer);
	std::cout << "Enter your darkest secret : ";
	if (!getline(std::cin, answer))
		return (1);
	this->_directory[index].set_darkest_secret(answer);
	return (0);
}

//TODO limit strings to 10 char and if string > 10 set the last char to .
int	Phonebook::search_function(void)
{
	int 		index = -1;
	std::string	input;

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	std::cout << "│         1│" << this->_directory[0].get_first_name() << "│" << this->_directory[0].get_last_name() << "│" << this->_directory[0].get_nickname() << "│" << std::endl;
	std::cout << "│         2│" << this->_directory[1].get_first_name() << "│" << this->_directory[1].get_last_name() << "│" << this->_directory[1].get_nickname() << "│" << std::endl;
	std::cout << "│         3│" << this->_directory[2].get_first_name() << "│" << this->_directory[2].get_last_name() << "│" << this->_directory[2].get_nickname() << "│" << std::endl;
	std::cout << "│         4│" << this->_directory[3].get_first_name() << "│" << this->_directory[3].get_last_name() << "│" << this->_directory[3].get_nickname() << "│" << std::endl;
	std::cout << "│         5│" << this->_directory[4].get_first_name() << "│" << this->_directory[4].get_last_name() << "│" << this->_directory[4].get_nickname() << "│" << std::endl;
	std::cout << "│         6│" << this->_directory[5].get_first_name() << "│" << this->_directory[5].get_last_name() << "│" << this->_directory[5].get_nickname() << "│" << std::endl;
	std::cout << "│         7│" << this->_directory[6].get_first_name() << "│" << this->_directory[6].get_last_name() << "│" << this->_directory[6].get_nickname() << "│" << std::endl;
	std::cout << "│         8│" << this->_directory[7].get_first_name() << "│" << this->_directory[7].get_last_name() << "│" << this->_directory[7].get_nickname() << "│" << std::endl;
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

	while (index < 0 || index > 8)
	{
		std::cout << "Enter contact index to display: ";
		if (!getline(std::cin, input))
			return (1);
		index = stoi(input);
		if (index < 0 || index > 8)
			std::cout << "contact " << index << " doesn't exist. Enter a contact index between 1 to 8." << std::endl;
	}
	std::cout << "Contact " << index << std::endl;
	std::cout << "First name: " << this->_directory[index -1].get_first_name() << std::endl;
	std::cout << "First name: " << this->_directory[index -1].get_last_name() << std::endl;
	std::cout << "First name: " << this->_directory[index -1].get_nickname() << std::endl;
	std::cout << "First name: " << this->_directory[index -1].get_phone_number() << std::endl;
	std::cout << "First name: " << this->_directory[index -1].get_darkest_secret() << std::endl;

	return (0);
}