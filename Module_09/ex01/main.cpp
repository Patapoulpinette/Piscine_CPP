/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:56:42 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/14 16:56:42 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN rpn;
		rpn.calculate(argv[1]);
	}
	else
		std::cerr << RED << "Error:" << NO_COLOR << " wrong number of arguments: "
				  << WHITE_ITALIC << "./RPN [inverted polish mathematical expression]" << NO_COLOR << std::endl;
	return 0;
}
