/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:08:15 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/09 19:08:15 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		virtual ~Intern();

		Intern &operator=(const Intern &rhs);

		AForm *makeForm(const std::string &name, const std::string &target);

		class FormDoesNotExistException : public std::exception
		{
			public:
				explicit FormDoesNotExistException(const std::string &name);
				virtual const char *what() const throw();
				virtual ~FormDoesNotExistException() throw();

			private:
				std::string _msg;
		};

	private:
		static AForm *_createShrubberyCreationForm(const std::string &target);
		static AForm *_createRobotomyRequestForm(const std::string &target);
		static AForm *_createPresidentialPardonForm(const std::string &target);
};

#endif //INTERN_HPP
