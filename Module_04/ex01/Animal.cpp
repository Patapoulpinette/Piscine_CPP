/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:36:36 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 14:36:36 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called\n";
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal &Animal::operator=(const Animal &rhs)
{
	_type = rhs._type;
	return (*this);
}

const std::string &Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "Animal noise\n";
}
