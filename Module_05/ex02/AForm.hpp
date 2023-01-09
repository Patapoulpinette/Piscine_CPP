/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:22:20 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/30 19:22:20 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150
# define RED "\033[0;31m"
# define NO_COLOR "\033[0m"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, int signedGrade, int executeGrade);
		AForm(const AForm &src);
		virtual ~AForm();

		AForm &operator=(const AForm &rhs);

		const std::string &getName() const;
		bool isSigned() const;
		int getSignedGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormIsNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormIsAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormExecutionFailedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		bool 				_signed;
		const int 			_signedGrade;
		const int 			_executeGrade;
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif //FORM_HPP
