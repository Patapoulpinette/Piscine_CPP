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

# define K 5

template<class T>
class PmergeMe
{
	public:
		PmergeMe(T &list) : _list(list) {}
		~PmergeMe() {}

		T getList() const
		{
			return _list;
		}

		void sort(int p, int r)
		{
			//TODO sorting algo
			if (r - p > K)
			{
				int q = (p + r) / 2;
				sort(_list, p, q);
				sort(_list, q + 1, r);
				merge(_list, p, q, r);
			}
			else
				insertionSort(_list, p, r);
		}

		//TODO translate in c++
//		void insertionSort(int p, int q)
//		{
//			for (int i = p; i < q; i++)
//			{
//				int tempVal = A[i + 1];
//				int j = i + 1;
//				while (j > p && A[j - 1] > tempVal) {
//					A[j] = A[j - 1];
//					j--;
//				}
//				A[j] = tempVal;
//			}
//			int[] temp = Arrays.copyOfRange(A, p, q +1);
//			Arrays.stream(temp).forEach(i -> System.out.print(i + " "));
//			System.out.println();
//		}
//
//		void merge(int p, int q, int r)
//		{
//			int n1 = q - p + 1;
//			int n2 = r - q;
//			int[] LA = Arrays.copyOfRange(A, p, q +1);
//			int[] RA = Arrays.copyOfRange(A, q+1, r +1);
//			int RIDX = 0;
//			int LIDX = 0;
//			for (int i = p; i < r - p + 1; i++)
//			{
//				if (RIDX == n2) {
//					A[i] = LA[LIDX];
//					LIDX++;
//				} else if (LIDX == n1) {
//					A[i] = RA[RIDX];
//					RIDX++;
//				} else if (RA[RIDX] > LA[LIDX]) {
//					A[i] = LA[LIDX];
//					LIDX++;
//				} else {
//					A[i] = RA[RIDX];
//					RIDX++;
//				}
//			}
//		}

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
