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
			//Calculating the size of sub-arrays
			int n1 = q - p + 1;					// size of list[p..q]
			int n2 = r - q;						// size of list[q+1..r]

			//Copy of sub-arrays left and right
			int Llist[n1], Rlist[n2];			// creation of 2 temporary sub-arrays
			for (int i = 0; i < n1; i++)
				Llist[i] = list[p + i];
			for (int i = 0; i < n2; i++)
				Rlist[i] = list[q + i + 1];

			//Fusion of sub-arrays left and right
			int RIDX = 0;						// index or right array
			int LIDX = 0;						//index or left array
			for (int i = p; i <= r; i++)		// i: index of list array
			{
				if (RIDX == n2) {
					list[i] = Llist[LIDX];
					LIDX++;
				} else if (LIDX == n1) {
					list[i] = Rlist[RIDX];
					RIDX++;
				} else if (Rlist[RIDX] > Llist[LIDX]) {
					list[i] = Llist[LIDX];
					LIDX++;
				} else {
					list[i] = Rlist[RIDX];
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
