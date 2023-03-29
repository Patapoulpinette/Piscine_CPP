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

bool parsing(std::vector<std::string> &args)
{
	if (args.empty())
		return false;
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
	{
		if (it->empty())
		{
			std::cout << RED << "Error:" << NO_COLOR << " only digits allowed" << std::endl;
			return false;
		}
		for (std::string::iterator ite = it->begin(); ite != it->end(); ite++)
		{
			if (!isdigit(*ite))
			{
				std::cout << RED << "Error:" << NO_COLOR << " only digits allowed" << std::endl;
				return false;
			}
		}
		double tmp = std::strtod(it->c_str(), NULL);
		if (tmp < 0 || tmp > std::numeric_limits<int>::max())
		{
			std::cout << RED << "Error:" << NO_COLOR << " must be a positive integer" << std::endl;
			return false;
		}
	}
	return true;
}


//MERGE-INSERTION ALGO in C++ ---------------------------------

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int K = 5;
//
//void insertionSort(int A[], int p, int q) {
//	for (int i = p; i < q; i++) {
//		int tempVal = A[i + 1];
//		int j = i + 1;
//		while (j > p && A[j - 1] > tempVal) {
//			A[j] = A[j - 1];
//			j--;
//		}
//		A[j] = tempVal;
//	}
//	for (int i = p; i <= q; i++) {
//		cout << A[i] << " ";
//	}
//	cout << endl;
//}
//
//void merge(int A[], int p, int q, int r) {
//	int n1 = q - p + 1;
//	int n2 = r - q;
//	int LA[n1], RA[n2];
//	for (int i = 0; i < n1; i++) {
//		LA[i] = A[p + i];
//	}
//	for (int i = 0; i < n2; i++) {
//		RA[i] = A[q + i + 1];
//	}
//	int RIDX = 0;
//	int LIDX = 0;
//	for (int i = p; i <= r; i++) {
//		if (RIDX == n2) {
//			A[i] = LA[LIDX];
//			LIDX++;
//		} else if (LIDX == n1) {
//			A[i] = RA[RIDX];
//			RIDX++;
//		} else if (RA[RIDX] > LA[LIDX]) {
//			A[i] = LA[LIDX];
//			LIDX++;
//		} else {
//			A[i] = RA[RIDX];
//			RIDX++;
//		}
//	}
//}
//
//void sort(int A[], int p, int r) {
//	if (r - p > K) {
//		int q = (p + r) / 2;
//		sort(A, p, q);
//		sort(A, q + 1, r);
//		merge(A, p, q, r);
//	} else {
//		insertionSort(A, p, r);
//	}
//}
//
//int main() {
//	int A[] = { 2, 5, 1, 6, 7, 3, 8, 4, 9 };
//	int n = sizeof(A)/sizeof(A[0]);
//	sort(A, 0, n - 1);
//	for (int i = 0; i < n; i++) {
//		cout << A[i] << " ";
//	}
//	return 0;
//}
//-------------------------------------------------------------
