/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:15:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/19 13:15:48 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{

}

Ice::Ice(const Ice &src)
{
	*this = src;
}

Ice::~Ice()
{

}

Ice &Ice::operator=(const Ice &rhs)
{
	return (*this);
}

AMateria *Ice::clone() const
{
	Ice *ice = new Ice;
	*ice = *this;
	return ice;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
