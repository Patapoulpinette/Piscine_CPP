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
	return;
}

// DESTRUCTOR ------------------------------------------------------------------

Phonebook::~Phonebook()
{
	return;
}

// OTHER FUNCTIONS -------------------------------------------------------------

/// REGISTERS A NEW CONTACT
/// Ask to the user to complete some informations and add them in the contact directory
/// \param index
/// \return
int	Phonebook::add_function(int index)
{
	std::string answer;
56892741
	while (answer.empty())
	{
		std::cout << "Enter your first name: ";
		if (!getline(std::cin, answer))
			return (1);
		if (answer.empty())
			std::cout << "Empty line, try again" << std::endl;
		this->_directory[index].set_first_name(answer);
	}
	answer.clear();
	while (answer.empty())
	{
		std::cout << "Enter your last name: ";
		if (!getline(std::cin, answer))
			return (1);
		if (answer.empty())
			std::cout << "Empty line, try again" << std::endl;
		this->_directory[index].set_last_name(answer);
	}
	answer.clear();
	while (answer.empty())
	{
		std::cout << "Enter your nickname: ";
		if (!getline(std::cin, answer))
			return (1);
		if (answer.empty())
			std::cout << "Empty line, try again" << std::endl;
		this->_directory[index].set_nickname(answer);
	}
	answer.clear();
	while (answer.empty())
	{
		std::cout << "Enter your phone number: ";
		if (!getline(std::cin, answer))
			return (1);
		if (answer.empty())
			std::cout << "Empty line, try again" << std::endl;
		if (answer.size() != 10)
		{
			std::cout << "Wrong format: 10 numbers needed without spaces [ex: 012356789]" << std::endl;
			answer.clear();
		}
		if (!is_only_digits(answer))
		{
			std::cout << "Enter only digits" << std::endl;
			answer.clear();
		}
		this->_directory[index].set_phone_number(answer);
	}
	answer.clear();
	while (answer.empty())
	{
		std::cout << "Enter your darkest secret: ";
		if (!getline(std::cin, answer))
			return (1);
		if (answer.empty())
			std::cout << "Empty line, try again" << std::endl;
		this->_directory[index].set_darkest_secret(answer);
	}
	return (0);
}

/// DISPLAYS THE REQUESTED CONTACT
/// Displays the array of contact if it is not empty,
/// then ask which contact to display and displays it if it is not empty
/// \return
int	Phonebook::search_function(void)
{
	int 		index = 0;
	std::string	input;
	std::string	output;

	if (this->_directory[index].get_first_name().empty() &&
		this->_directory[index + 1].get_first_name().empty() &&
		this->_directory[index + 2].get_first_name().empty() &&
		this->_directory[index + 3].get_first_name().empty() &&
		this->_directory[index + 4].get_first_name().empty() &&
		this->_directory[index + 5].get_first_name().empty() &&
		this->_directory[index + 6].get_first_name().empty() &&
		this->_directory[index + 7].get_first_name().empty())
		std::cout << "Empty directory" << std::endl;
	else
	{
		//Display array of contacts
		std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
		std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
		std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
		while (index < 8)
		{
			if (this->_directory[index].get_first_name() != "")
			{
				std::cout << "│" << std::setw(10) << index + 1 << "│";
				if (this->_directory[index].get_first_name().size() > 10)
				{
					output.assign(this->_directory[index].get_first_name(), 0, 9);
					output.append(".");
					std::cout << output << "│";
				} else
					std::cout << std::setw(10) << this->_directory[index].get_first_name() << "│";
				if (this->_directory[index].get_last_name().size() > 10)
				{
					output.assign(this->_directory[index].get_last_name(), 0, 9);
					output.append(".");
					std::cout << output << "│";
				} else
					std::cout << std::setw(10) << this->_directory[index].get_last_name() << "│";
				if (this->_directory[index].get_nickname().size() > 10)
				{
					output.assign(this->_directory[index].get_nickname(), 0, 9);
					output.append(".");
					std::cout << output << "│" << std::endl;
				} else
					std::cout << std::setw(10) << this->_directory[index].get_nickname() << "│" << std::endl;
			}
			index++;
		}
		std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

		//Ask which contact to display and displays it
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
					std::cout << "contact " << index << " doesn't exist. Enter a contact index between 1 to 8."
							  << std::endl;
			} else
				std::cout << "Please, enter only 1 digit" << std::endl;
		}
		if (this->_directory[index - 1].get_first_name() != "")
		{
			std::cout << "Contact " << index << std::endl;
			std::cout << "First name: " << this->_directory[index - 1].get_first_name() << std::endl;
			std::cout << "Last name: " << this->_directory[index - 1].get_last_name() << std::endl;
			std::cout << "Nickname: " << this->_directory[index - 1].get_nickname() << std::endl;
			std::cout << "Phone number: " << this->_directory[index - 1].get_phone_number() << std::endl;
			std::cout << "Darkest secret: " << this->_directory[index - 1].get_darkest_secret() << std::endl;
		} else
			std::cout << "Empty contact" << std::endl;
	}

	return (0);
}

/// Checks if the string str has only digits
/// \param str
/// \return 1 if there is only digits in the string str, else 0
int is_only_digits(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
