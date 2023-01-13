/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:38:41 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/13 17:10:52 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	//with array of int -------------------------------------------------------
	std::cout << "─── Array of INT ────" << std::endl;

	int array1[5] = { 1, 2, 3, 4, 5 };
	int size1 = 5;

	std::cout << "Origin:     ";
	for (int i = 0; i < size1; i++)
		std::cout << array1[i] << " ";
	std::cout << std::endl;

	iter(array1, size1, &add_two);

	std::cout << "After iter: ";
	for (int i = 0; i < size1; i++)
		std::cout << array1[i] << " ";
	std::cout << std::endl;

	//with array of float -----------------------------------------------------
	std::cout << "\n─── Array of FLOAT ────────────" << std::endl;

	float array2[5] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
	int size2 = 5;

	std::cout << "Origin:     ";
	for (int i = 0; i < size2; i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;

	iter(array2, size2, &add_two);

	std::cout << "After iter: ";
	for (int i = 0; i < size2; i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;

	// With array of char -----------------------------------------------------
	std::cout << "\n─── Array of CHAR ───" << std::endl;

	char array3[5] = { 'A', 'B', 'C', 'D', 'E' };
	int size3 = 5;

	std::cout << "Origin:     ";
	for (int i = 0; i < size3; i++)
		std::cout << array3[i] << " ";
	std::cout << std::endl;

	iter(array3, size3, &add_two);

	std::cout << "After iter: ";
	for (int i = 0; i < size3; i++)
		std::cout << array3[i] << " ";
	std::cout << std::endl;

	return 0;
}
