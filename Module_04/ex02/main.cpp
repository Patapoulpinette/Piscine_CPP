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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const AAnimal *array[10];

	for (int index = 0; index < 4; index++)
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

//	const AAnimal	animal;
//	animal.makeSound();

	return (0);
}
