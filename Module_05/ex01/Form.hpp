/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form
{
	public:
		Form();
		Form(const std::string &name, int signedGrade, int executeGrade);
		Form(const Form &src);
		virtual ~Form();

		Form &operator=(const Form &rhs);

		const std::string &getName() const;
		bool isSigned() const;
		int getSignedGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat &bureaucrat);

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

	private:
		const std::string	_name;
		bool 				_signed;
		const int 			_signedGrade;
		const int 			_executeGrade;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif //FORM_HPP
