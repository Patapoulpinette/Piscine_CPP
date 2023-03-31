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
		clock_t time;

		//Parsing --------------------------------------------------------------
		std::vector<std::string> strVector(argv + 1, argv + argc);
		if (!parsing(strVector))
			return 1;

		//Sorting with Vector --------------------------------------------------
		time = clock();
		std::vector<unsigned int> uIntVector = convert<std::vector<unsigned int>, std::vector<std::string> >(strVector);
		PmergeMe<std::vector<unsigned int> > vector(uIntVector);
		vector.print("input of vector");
		vector.sort(vector.getList(), 0, static_cast<int>(vector.getList().size() - 1));
		vector.print("Sorted with vector");
		time = clock() - time;
		std::cout << "Time to sort with vector: " << static_cast<float>(time) / CLOCKS_PER_SEC * 1000 << " ms\n" << std::endl;

		//Sorting with Vector --------------------------------------------------
		time = clock();
		std::deque<std::string> strDeque(argv + 1, argv + argc);
		std::deque<unsigned int> uIntDeque = convert<std::deque<unsigned int>, std::deque<std::string> >(strDeque);
		PmergeMe<std::deque<unsigned int> > deque(uIntDeque);
		deque.print("input of deque"); //TODO to remove (test)
		deque.sort(deque.getList(), 0, static_cast<int>(deque.getList().size() - 1));
		deque.print("Sorted with Deque"); //TODO to remove (test)
		time = clock() - time;
		std::cout << "Time to sort with deque: " << static_cast<float>(time) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	}
	return 0;
}
