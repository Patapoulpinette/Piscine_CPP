/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:42:02 by dbouron           #+#    #+#             */
/*   Updated: 2023/03/29 14:42:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <limits>

# define RED "\033[0;31m"
# define NO_COLOR "\033[0m"

template<class T>
class PmergeMe
{
	public:
		PmergeMe(T &list) : _list(list) {}
		~PmergeMe() {}

		void sort()
		{
			print("Input");
		}

		void print(const std::string &msg)
		{
			std::cout << msg << ": ";
//			for (size_t i = 0; i < list.size(); i++)
//				std::cout << list[i] << " ";
			for (typename T::iterator it = _list.begin(); it != _list.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

	private:
		PmergeMe() {}
		PmergeMe(const PmergeMe &src) { *this = src; }

		PmergeMe &operator=(const PmergeMe &rhs)
		{
			//TODO at the end
			(void) rhs;
			return *this;
		}

	private:
		T	_list;
};

bool						parsing(std::vector<std::string> &args);

template<typename T, typename U>
T	convert(U &strVector)
{
	T uIntVector;
	for (typename U::iterator it = strVector.begin(); it != strVector.end(); it++)
		uIntVector.push_back(static_cast<int>(std::strtod(it->c_str(), NULL)));
	return uIntVector;
}

#endif //PMERGEME_HPP
