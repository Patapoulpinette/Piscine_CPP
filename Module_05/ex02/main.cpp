/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:06:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/29 12:06:23 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat Albert("Albert", 30);
		Bureaucrat Alice("Alice", 1);
		Bureaucrat Random;

		ShrubberyCreationForm A("Epicea");
		RobotomyRequestForm B("Jason");
		PresidentialPardonForm C("Wilson");

		std::cout << "\n ─── BUREAUBRATS ───" << std::endl;
		std::cout << Albert << std::endl;
		std::cout << Alice << std::endl;
		std::cout << Random << std::endl;

		std::cout << "\n ─── FORMS ───" << std::endl;
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;

		std::cout << "\n ─── ALBERT ───" << std::endl;
		Albert.signForm(A);
		Albert.decrementGrade();
		std::cout << Albert << std::endl;
		Albert.signForm(A);
		Albert.signForm(B);
		Albert.signForm(C);

		std::cout << "\n ─── ALICE ───" << std::endl;
		Alice.executeForm(A);
		Alice.executeForm(B);
		Alice.executeForm(C);

		std::cout << "\n ─── RANDOM ───" << std::endl;
		Random.executeForm(A);
		Random.executeForm(B);
		Random.executeForm(C);

		std::cout << "\n ─── FORMS ───" << std::endl;
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
