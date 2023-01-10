/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:08:05 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/09 19:08:05 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	try
	{
		AForm *(*arrayptr[])(const std::string &target) =
				{
						&Intern::_createShrubberyCreationForm,
						&Intern::_createRobotomyRequestForm,
						&Intern::_createPresidentialPardonForm
				};
		std::string arraystr[] =
				{
						"shrubbery creation",
						"robotomy request",
						"presidential pardon"
				};
		for (int i = 0; i < 3; i++)
		{
			if (name == arraystr[i])
			{
				std::cout << "Intern creates " << name << " form" << std::endl;
				return (*arrayptr[i])(target);
			}
		}
		throw FormDoesNotExistException(name);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}

AForm *Intern::_createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::_createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::_createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

// EXCEPTIONS ------------------------------------------------------------------

Intern::FormDoesNotExistException::FormDoesNotExistException(const std::string &name)
{
	std::stringstream	str;
	str << RED"Intern: form \"" << name << "\" doesn't exist"NO_COLOR;
	_msg = str.str();
}

const char *Intern::FormDoesNotExistException::what() const throw()
{
	return _msg.c_str();
}

Intern::FormDoesNotExistException::~FormDoesNotExistException() throw()
{

}
