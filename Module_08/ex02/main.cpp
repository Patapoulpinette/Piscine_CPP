/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:16:21 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/17 19:41:09 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main()
{
	std::cout << "Tests with MutantStack -----------" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Access next element: " << mstack.top() << std::endl;

		std::cout << "Remove top element" << std::endl;
		mstack.pop();

		std::cout << "Return size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

// --- To compare the results with list ------------------------------------

	std::cout << "Tests with list -----------" << std::endl;
	{
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << "Access first element: " << lst.front() << std::endl;

		std::cout << "Delete first element" << std::endl;
		lst.pop_front();

		std::cout << "Return size: " << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(lst);
	}

	return 0;
}
