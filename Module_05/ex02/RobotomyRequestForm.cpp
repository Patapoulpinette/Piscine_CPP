/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:35:09 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/09 10:35:09 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm(target + "_robotomy", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	AForm(src)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void) rhs;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::cout << "Makes drill noises...\n";
	srand(time(NULL));
	int nb = rand() % 2;
	if (nb)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Execution failed" << std::endl;
}
