/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:33:12 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/09 10:33:12 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm(target + "_shrubbery", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	AForm(src)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	(void) rhs;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::ofstream file(_target + "_shrubbery", std::ios::out);
	if (!file.is_open())
	{
		std::cerr << "Error: failed to create " << file << std::endl;
		exit(EXIT_FAILURE);
	}

	file <<
	"     ccee88oo\n"
	"  C8O8O8Q8PoOb o8oo\n"
	" dOB69QO8PdUOpugoO9bD\n"
	"CgggbU8OU qOp qOdoUOdcb\n"
	"    6OuU  /p u gcoUodpP\n"
	"      \\\\\\//  /douUP\n"
	"        \\\\\\////\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   .....//||||\\...."
	<< std::endl;

	file.close();
}
