/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:16:46 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/17 17:15:12 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int	main()
{
	Span sp = Span(10);

	sp.addNumber(-6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(28);
	sp.addNumber(42);
	sp.addNumber(-1);

	sp.printSpan();

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> vec1;
	for (int i = 0; i < 9000; i++)
		vec1.push_back(std::rand());

	sp.addNumbers(vec1);
	sp.printSpan();

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
