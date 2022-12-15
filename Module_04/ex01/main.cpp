/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:06:56 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 16:06:56 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *array[10];

	for (int index = 0; index < 10; index++)
	{
		if (index % 2 == 0)
		{
			array[index] = new Dog();
			std::cout << array[index]->getType() << std::endl;
			array[index]->makeSound();
			delete(array[index]);
		}
		else
		{
			array[index] = new Cat();
			std::cout << array[index]->getType() << std::endl;
			array[index]->makeSound();
			delete(array[index]);
		}
	}

	std::cout << "---------------------------------------" << std::endl;

	Dog test;
	{
		Dog tmp = test;
	}
	std::cout << test.getType() << std::endl;

	return (0);
}
