/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:36:36 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 14:36:36 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called\n";
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	_type = rhs._type;
	return (*this);
}

const std::string &AAnimal::getType() const
{
	return _type;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal noise\n";
}
