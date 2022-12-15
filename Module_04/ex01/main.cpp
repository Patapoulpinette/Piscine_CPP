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

	std::cout << "---------------------------------------" << std::endl;

	Dog test;
	{
		test.getDogBrain()->setIdeas(0, "Sleep");//Some examples
		test.getDogBrain()->setIdeas(1, "Eat");
		test.getDogBrain()->setIdeas(2, "Play");
		test.getDogBrain()->setIdeas(3, "Drink");
		test.getDogBrain()->setIdeas(4, "Run");
		test.getDogBrain()->setIdeas(5, "Go for a walk");
		test.getDogBrain()->setIdeas(6, "Sit down");
		Dog tmp = test;
		std::cout << tmp.getDogBrain()->getIdeas(4) << std::endl;
		std::cout << tmp.getDogBrain()->getIdeas(6) << std::endl;
	}
	std::cout << test.getType() << std::endl;
	std::cout << test.getDogBrain()->getIdeas(2) << std::endl;
	std::cout << test.getDogBrain()->getIdeas(6) << std::endl;

	return (0);
}
