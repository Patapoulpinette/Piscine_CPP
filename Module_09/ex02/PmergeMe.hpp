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
# include <ctime>

# define RED "\033[0;31m"
# define NO_COLOR "\033[0m"

# define K 5

template<class T>
class PmergeMe
{
	public:
		PmergeMe(T &list) : _list(list) {}
		~PmergeMe() {}

		T &getList() { return _list; }

		void sort(T &list, int p, int r)
		{
			if (r - p > K)
			{
				int q = (p + r) / 2;
				sort(list, p, q);
				sort(list, q + 1, r);
				merge(list, p, q, r);
			}
			else
				insertionSort(list, p, r);
		}

		void insertionSort(T &list, int p, int q)
		{
			for (int i = p; i < q; i++)
			{
				int tempVal = list[i + 1];
				int j = i + 1;
				while (j > p && static_cast<int>(list[j - 1]) > tempVal)
				{
					list[j] = list[j - 1];
					j--;
				}
				list[j] = tempVal;
			}
		}

		void merge(T &list, int p, int q, int r)
		{
			int n1 = q - p + 1;
			int n2 = r - q;
			int LA[n1], RA[n2];
			for (int i = 0; i < n1; i++)
				LA[i] = list[p + i];
			for (int i = 0; i < n2; i++)
				RA[i] = list[q + i + 1];
			int RIDX = 0;
			int LIDX = 0;
			for (int i = p; i <= r; i++)
			{
				if (RIDX == n2) {
					list[i] = LA[LIDX];
					LIDX++;
				} else if (LIDX == n1) {
					list[i] = RA[RIDX];
					RIDX++;
				} else if (RA[RIDX] > LA[LIDX]) {
					list[i] = LA[LIDX];
					LIDX++;
				} else {
					list[i] = RA[RIDX];
					RIDX++;
				}
			}
		}

		void print(const std::string &msg)
		{
			std::cout << msg << ": ";
			for (typename T::iterator it = _list.begin(); it != _list.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

	private:
		PmergeMe() {}
		PmergeMe(const PmergeMe &src) { *this = src; }

		PmergeMe &operator=(const PmergeMe &rhs)
		{
			_list = rhs._list;
			return *this;
		}

	private:
		T	_list;
};

bool parsing(std::vector<std::string> &args);

template<typename T, typename U>
T convert(U &strVector)
{
	T uIntVector;
	for (typename U::iterator it = strVector.begin(); it != strVector.end(); it++)
		uIntVector.push_back(static_cast<int>(std::strtod(it->c_str(), NULL)));
	return uIntVector;
}

#endif //PMERGEME_HPP
