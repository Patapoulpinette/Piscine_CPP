/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:19:25 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/10 13:19:25 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iomanip>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Convert	literal(argv[1]);
        std::cout << std::fixed << std::setprecision(1);
		std::cout << literal << std::endl;
	}
	else
		std::cerr << "Wrong number of arguments: ./convert [argument]" << std::endl;
	return 0;
}
