/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:38:00 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/21 15:38:00 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << &string << " [string address]" << std::endl;
	std::cout << stringPTR << " [stringPTR address]" << std::endl;
	std::cout << &stringREF << " [stringREF address]" << std::endl;

	std::cout << string << " [value of string]" << std::endl;
	std::cout << *stringPTR << " [pointed value of stringPTR]" << std::endl;
	std::cout << stringREF << " [pointed value of stringREF]" << std::endl;
	return (0);
}