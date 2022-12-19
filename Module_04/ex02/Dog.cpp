/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:44:40 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 15:44:40 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called\n";
	_type = "Dog";
	_dogBrain = new(Brain);
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called\n";
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete(_dogBrain);
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Assignation operator called\n";
	_type = rhs._type;
	delete(_dogBrain);
	_dogBrain = new Brain(*rhs._dogBrain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof\n";
}

Brain *Dog::getDogBrain() const
{
	return _dogBrain;
}
