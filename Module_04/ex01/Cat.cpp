/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:50:20 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 15:50:20 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called\n";
	_type = "Cat";
	_catBrain = new(Brain);
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called\n";
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete(_catBrain);
}

Cat &Cat::operator=(const Cat &rhs)
{
	_type = rhs._type;
	_catBrain = new Brain(*rhs._catBrain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaow\n";
}

Brain *Cat::getCatBrain() const
{
	return _catBrain;
}
