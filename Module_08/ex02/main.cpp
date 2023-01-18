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
	std::cout << "─ TESTS WITH MUTANTSTACK ───────────────" << std::endl;
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

// ─── To compare the results with list ────────────────────────────────────

	std::cout << "\n─ TESTS WITH LIST ──────────────────────" << std::endl;
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

// ─── Some other tests ────────────────────────────────────────────────────

	std::cout << "\n─ MY TESTS ─────────────────────────────" << std::endl;
	{
		MutantStack<int> mStack;
		mStack.push(-56);
		mStack.push(35);
		mStack.push(-29);
		mStack.push(22);
		mStack.push(42);
		MutantStack<int> copy = mStack;

		std::cout << "mStack size:  " << mStack.size() << "\t\tcopy size:  " << copy.size() << std::endl;
		std::cout << "mStack begin: " << *mStack.begin() << "\tcopy begin: " << *copy.begin() << std::endl;
		std::cout << "mStack end:   " << *(mStack.end() - 1) << "\tcopy end:   " << *(copy.end() - 1) << std::endl;
		std::cout << std::endl;

		for (MutantStack<int>::iterator i = mStack.end() - 1; i >= mStack.begin(); i--)
			mStack.pop();
		mStack.push(12);

		std::cout << "mStack size:  " << mStack.size() << "\t\tcopy size:  " << copy.size() << std::endl;
		std::cout << "mStack begin: " << *mStack.begin() << "\tcopy begin: " << *copy.begin() << std::endl;
		std::cout << "mStack end:   " << *(mStack.end() - 1) << "\tcopy end:   " << *(copy.end() - 1) << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
