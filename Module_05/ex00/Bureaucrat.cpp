/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:07:26 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/29 12:07:26 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Random"), _grade(MIN_GRADE)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{

	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	_name = rhs._name;
	_grade = rhs._grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Upgrading " << _name << "..." << std::endl;
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Downgrading " << _name << "..." << std::endl;
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
