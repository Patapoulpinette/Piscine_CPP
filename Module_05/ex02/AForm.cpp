/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:22:10 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/30 19:22:10 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Standard_form"), _signed(false),
				_signedGrade(MIN_GRADE), _executeGrade(MIN_GRADE)
{

}

AForm::AForm(const std::string &name, int signedGrade, int executeGrade) :
	_name(name), _signed(false), _signedGrade(signedGrade), _executeGrade(executeGrade)
{
	if (_signedGrade < MAX_GRADE || _executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_signedGrade > MIN_GRADE || _executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _signedGrade(src._signedGrade), _executeGrade(src._executeGrade)
{
	*this = src;
}

AForm::~AForm()
{

}

AForm &AForm::operator=(const AForm &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getSignedGrade() const
{
	return _signedGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signedGrade)
	{
		if (isSigned())
			throw FormIsAlreadySignedException();
		_signed = true;
	}
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > _signedGrade)
		throw GradeTooLowException();
	if (!isSigned())
		throw FormIsNotSignedException();
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	if (rhs.isSigned())
		o << rhs.getName() << " form is SIGNED, it needs a grade of " << rhs.getSignedGrade()
		<< " to be signed and a grade of " << rhs.getExecuteGrade()
		<< " to be executed";
	else
		o << rhs.getName() << " form is NOT SIGNED, it needs a grade of " << rhs.getSignedGrade()
		<< " to be signed and a grade of " << rhs.getExecuteGrade()
		<< " to be executed";
	return (o);
}

// EXCEPTIONS ------------------------------------------------------------------

const char *AForm::GradeTooHighException::what() const throw()
{
	return (RED"Form: grade is too high"NO_COLOR);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (RED"Form: grade is too low"NO_COLOR);
}

const char *AForm::FormIsNotSignedException::what() const throw()
{
	return (RED"Form: form is not signed"NO_COLOR);
}

const char *AForm::FormIsAlreadySignedException::what() const throw()
{
	return (RED"Form: form is already signed"NO_COLOR);
}

const char *AForm::FormExecutionFailedException::what() const throw()
{
	return (RED"Form: execution failed"NO_COLOR);
}
