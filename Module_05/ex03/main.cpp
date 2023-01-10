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
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat Albert("Albert", 30);
		Bureaucrat Alice("Alice", 1);
		Bureaucrat Random;

		Intern JB;
		Intern PA;

		std::cout << "\n ─── BUREAUCRATS ───" << std::endl;
		std::cout << Albert << std::endl;
		std::cout << Alice << std::endl;
		std::cout << Random << std::endl;

		std::cout << "\n ─── FORMS CREATION ───" << std::endl;
		AForm *A = JB.makeForm("shrubbery creation", "Epicea");
		AForm *B = JB.makeForm("robotomy request", "Jason");
		AForm *C = PA.makeForm("presidential pardon", "Wilson");
		AForm *D = PA.makeForm("ShrubberyCreation", "Pouet");

		AForm E("B", 30, 50);

		std::cout << "\n ─── FORMS ───" << std::endl;
		std::cout << *A << std::endl;
		std::cout << *B << std::endl;
		std::cout << *C << std::endl;
		if (D)
			std::cout << *D << std::endl;
		std::cout << E << std::endl;

		std::cout << "\n ─── ALBERT ───" << std::endl;
		Albert.signForm(*A);
		Albert.signForm(*B);
		Albert.decrementGrade();
		std::cout << Albert << std::endl;
		Albert.signForm(*A);
		Albert.signForm(*B);
		Albert.signForm(*C);
		Albert.signForm(E);

		std::cout << "\n ─── ALICE ───" << std::endl;
		Alice.executeForm(*A);
		Alice.executeForm(*B);
		Alice.executeForm(*C);
		Alice.executeForm(E);

		std::cout << "\n ─── FORMS ───" << std::endl;
		std::cout << *A << std::endl;
		std::cout << *B << std::endl;
		std::cout << *C << std::endl;
		std::cout << E << std::endl;

		delete A;
		delete B;
		delete C;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
