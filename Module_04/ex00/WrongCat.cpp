/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:10:55 by dbouron           #+#    #+#             */
/*   Updated: 2022/12/14 17:10:55 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Miaow\n";
}
