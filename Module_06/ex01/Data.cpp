/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:19:26 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/12 15:23:21 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {}
Data::Data(const Data &src) { *this = src; }
Data &Data::operator=(const Data &rhs) { _value = rhs._value; return *this; }
Data::~Data() {}

unsigned int Data::getValue() const
{
	return _value;
}

void Data::setValue(unsigned int value)
{
	_value = value;
}
