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

Fixed::Fixed() : _number(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_number = value << this->_bits;
	return;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(value * (1 << this->_bits));
	return;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

void	Fixed::setRawBits(const int raw)
{
	this->_number = raw;
	return;
}

int Fixed::getRawBits() const
{
	return (this->_number);
}

float	Fixed::toFloat() const
{
	return ((float) this->_number / (1 << this->_bits));
}

int	Fixed::toInt() const
{
	return (this->_number >> this->_bits);
}


//A revoir !
//bool Fixed::operator<(const Fixed &rhs) { /* do actual comparison */ }
//bool Fixed::operator>(const Fixed &rhs) { return (rhs < *this); }
//bool Fixed::operator<=(const Fixed &rhs) { return !(*this > rhs); }
//bool Fixed::operator>=(const Fixed &rhs) { return !(*this < rhs); }
//bool Fixed::operator==(const Fixed &rhs) { /* do actual comparison */ }
//bool Fixed::operator!=(const Fixed &rhs) { return !(*this == rhs); }
