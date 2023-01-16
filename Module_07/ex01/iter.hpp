/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:39:12 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/13 17:10:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template<typename typeT>
void iter(typeT array[], int size, void (*function)(typeT const &arg))
{
	for (int i = 0; i < size; i++)
		function(array[i]);
}

template<typename typeT>
void iter2(typeT array[], int size, void (*function)(typeT &arg))
{
	for (int i = 0; i < size; i++)
		function(array[i]);
}

template<typename typeT>
void display(typeT const &arg) { std::cout << arg << " "; }

template<typename typeT>
void add_two(typeT &arg) { arg = arg + 2; }

#endif //ITER_HPP
