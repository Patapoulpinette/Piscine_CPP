/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:22:10 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/30 19:22:10 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Standard_form"), _signed(false),
				_signedGrade(MIN_GRADE), _executeGrade(MIN_GRADE)
{

}

Form::Form(const std::string &name, int signedGrade, int executeGrade) :
	_name(name), _signed(false), _signedGrade(signedGrade), _executeGrade(executeGrade)
{
	if (signedGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	else if (signedGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &src)
{
	*this = src;
}

Form::~Form()
{

}

Form &Form::operator=(const Form &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getSignedGrade() const
{
	return _signedGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signedGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	if (rhs.isSigned())
		o << rhs.getName() << " form is SIGNED, it needs a grade of " << rhs.getSignedGrade()
		<< " to be signed and a grade of " << rhs.getExecuteGrade()
		<< " to be executed" << std::endl;
	else
		o << rhs.getName() << " form is NOT SIGNED, it needs a grade of " << rhs.getSignedGrade()
		<< " to be signed and a grade of " << rhs.getExecuteGrade()
		<< " to be executed" << std::endl;
	return (o);
}
