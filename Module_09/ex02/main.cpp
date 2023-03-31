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
		clock_t vectorTime;
		clock_t dequeTime;

		//Parsing --------------------------------------------------------------
		std::vector<std::string> strVector(argv + 1, argv + argc);
		if (!parsing(strVector))
			return 1;
		std::deque<std::string> strDeque(argv + 1, argv + argc);

		//Display input --------------------------------------------------------
		std::cout << "Input: ";
		for (std::vector<std::string>::iterator it = strVector.begin(); it != strVector.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		//Sorting with Vector --------------------------------------------------
		std::vector<unsigned int> uIntVector = convert<std::vector<unsigned int>, std::vector<std::string> >(strVector);
		PmergeMe<std::vector<unsigned int> > vector(uIntVector);
		vectorTime = clock();
		vector.sort(vector.getList(), 0, static_cast<int>(vector.getList().size() - 1));
		vectorTime = clock() - vectorTime;

		//Sorting with Deque ---------------------------------------------------
		std::deque<unsigned int> uIntDeque = convert<std::deque<unsigned int>, std::deque<std::string> >(strDeque);
		PmergeMe<std::deque<unsigned int> > deque(uIntDeque);
		dequeTime = clock();
		deque.sort(deque.getList(), 0, static_cast<int>(deque.getList().size() - 1));
		dequeTime = clock() - dequeTime;

		//Display outputs ------------------------------------------------------
		vector.print("Sorted with vector");
		deque.print("Sorted with Deque"); //TODO to remove (test)
		std::cout << "Time to sort with vector: " << static_cast<float>(vectorTime) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
		std::cout << "Time to sort with deque: " << static_cast<float>(dequeTime) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	}
	return 0;
}
