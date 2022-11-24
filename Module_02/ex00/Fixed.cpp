/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:43:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/24 11:43:48 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _width(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &) : _width(0)
{
	std::cout << "Copy constructor called" << std::endl;
	getRawBits();
	return;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(const Fixed &)
{
	std::cout << "Copy assigment operator called" << std::endl;
	getRawBits();
	return (*this);
}

void	Fixed::setRawBits(const int raw)
{
	this->_width = raw;
	return;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_width);
}
