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

int main()
{
	try
	{
		Bureaucrat Albert("Albert", 50);
		Bureaucrat Alice("Alice", 1);
		//Bureaucrat Albane("Albane", 500);
		Bureaucrat Random;

		Form A;
		Form B("B", 30, 50);

		std::cout << "\n ─── BUREAUCRATS ───" << std::endl;
		std::cout << Albert << std::endl;
		std::cout << Alice << std::endl;
		std::cout << Random << std::endl;

		std::cout << "\n ─── FORMS ───" << std::endl;
		std::cout << A << std::endl;
		std::cout << B << std::endl;

		std::cout << "\n ─── ALBERT ───" << std::endl;
		A.beSigned(Albert);
		Albert.signForm(A);
		B.beSigned(Albert);
		Albert.signForm(B);
		Albert.decrementGrade();
		std::cout << Albert << std::endl;
		A.beSigned(Albert);
		Albert.signForm(A);
		B.beSigned(Albert);
		Albert.signForm(B);

		std::cout << "\n ─── ALICE ───" << std::endl;
		Alice.incrementGrade();
		std::cout << Alice << std::endl;

		std::cout << "\n ─── RANDOM ───" << std::endl;
		Random.incrementGrade();
		std::cout << Random << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}