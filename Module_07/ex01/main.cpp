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
	// With array of string -----------------------------------------------------
	std::cout << "─── Array of STRING ───────────" << std::endl;

	std::string array1[5] = { "ABC", "BCD", "CDE", "DEF", "EFG" };
	int size1 = 5;

	std::cout << "Origin:     ";
	for (int i = 0; i < size1; i++)
		std::cout << array1[i] << " ";
	std::cout << std::endl;

	std::cout << "After iter: ";
	iter(array1, size1, display);
	std::cout << std::endl;

	//with array of int -------------------------------------------------------
	std::cout << "\n─── Array of INT ────" << std::endl;

	int array2[5] = { 1, 2, 3, 4, 5 };
	int size2 = 5;

	std::cout << "Origin:     ";
	for (int i = 0; i < size2; i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;

	std::cout << "After iter: ";
	iter2(array2, size2, add_two);
	iter(array2, size2, display);
	std::cout << std::endl;

	//with array of float -----------------------------------------------------
	std::cout << "\n─── Array of FLOAT ────────────" << std::endl;

	float array3[5] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
	int size3 = 5;

	std::cout << "Origin:     ";
	for (int i = 0; i < size3; i++)
		std::cout << array3[i] << " ";
	std::cout << std::endl;

	std::cout << "After iter: ";
	iter2(array3, size3, add_two);
	iter(array3, size3, display);
	std::cout << std::endl;

	// With array of char -----------------------------------------------------
	std::cout << "\n─── Array of CHAR ───" << std::endl;

	char array4[5] = { 'A', 'B', 'C', 'D', 'E' };
	int size4 = 5;

	std::cout << "Origin:     ";
	for (int i = 0; i < size4; i++)
		std::cout << array4[i] << " ";
	std::cout << std::endl;

	std::cout << "After iter: ";
	iter2(array4, size4, add_two);
	iter(array4, size4, display);
	std::cout << std::endl;

	return 0;
}
