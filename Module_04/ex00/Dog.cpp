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
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called\n";
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog &Dog::operator=(const Dog &rhs)
{
	_type = rhs._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof\n";
}
