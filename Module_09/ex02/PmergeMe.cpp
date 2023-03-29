/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:42:02 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/29 14:42:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<class T>
PmergeMe<T>::PmergeMe() {}

template<class T>
PmergeMe<T>::PmergeMe(T &list)
	: _list(list) {}

template<class T>
PmergeMe<T>::PmergeMe(const PmergeMe &src) { *this = src; }

template<class T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &rhs)
{
	//TODO at the end
	(void) rhs;
	return *this;
}

template<class T>
PmergeMe<T>::~PmergeMe() {}

template<class T>
void PmergeMe<T>::sort()
{
	print("Input", _list);
	std::vector<int> v;
	v.push_back(12);
	v.push_back(42);
	v.push_back(1);
	v.push_back(12324);
	v.push_back(8);
	v.push_back(12387);
	v.push_back(39);
	print("test", v);
}

template<class T>
void PmergeMe<T>::print(const std::string &msg)
{
	std::cout << msg << ": ";
//	for (size_t i = 0; list[i]; i++)
//		std::cout << list[i] << " ";
	for (typename T::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
