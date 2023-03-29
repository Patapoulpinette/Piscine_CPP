/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:43:01 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/29 14:43:01 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::vector<std::string> strVector(argv + 1, argv + argc);
		if (!parsing(strVector))
			return 1;
		std::deque<std::string> strDeque(argv + 1, argv + argc);
		std::vector<unsigned int> uIntVector = convert<std::vector<unsigned int>, std::vector<std::string> >(strVector);
		std::deque<unsigned int> uIntDeque = convert<std::deque<unsigned int>, std::deque<std::string> >(strDeque);
		PmergeMe<std::vector<unsigned int> > vector(uIntVector);
		PmergeMe<std::deque<unsigned int> > deque(uIntDeque);
		vector.print("input of vector");
		deque.print("input of deque"); //TODO to remove (test)
		vector.sort();
		deque.sort();
		vector.print("Sorted with vector");
		deque.print("Sorted with Deque"); //TODO to remove (test)
	}
	return 0;
}
