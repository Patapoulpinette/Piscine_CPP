/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:08:20 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/15 16:08:20 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

// CONSTRUCTOR -----------------------------------------------------------------

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	return;
}

// DESTRUCTOR ------------------------------------------------------------------

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return;
}

// SET FUNCTIONS ---------------------------------------------------------------

void	Contact::set_first_name(std::string value)
{
	this->_first_name = value;
	return;
}

void	Contact::set_last_name(std::string value)
{
	this->_last_name = value;
	return;
}

void	Contact::set_nickname(std::string value)
{
	this->_nickname = value;
	return;
}

void	Contact::set_phone_number(std::string value)//TODO check if it is only digits et +
{
	this->_phone_number = value;
	return;
}

void	Contact::set_darkest_secret(std::string value)
{
	this->_darkest_secret = value;
	return;
}

// GET FUNCTIONS ---------------------------------------------------------------

std::string Contact::get_first_name() const
{
	return this->_first_name;
}

std::string Contact::get_last_name() const
{
	return this->_last_name;
}

std::string Contact::get_nickname() const
{
	return this->_nickname;
}

std::string Contact::get_phone_number() const
{
	return this->_phone_number;
}

std::string Contact::get_darkest_secret() const
{
	return this->_darkest_secret;
}