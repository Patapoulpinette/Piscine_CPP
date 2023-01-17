/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:41 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/17 19:13:22 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack<T> &src) { *this = src; }
		MutantStack<T> &operator=(const MutantStack<T> &rhs) { this->c = rhs.c; return *this; }
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

	private:

};

#endif //MUTANTSTACK_HPP
